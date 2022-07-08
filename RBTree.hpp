/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:12:27 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/09 00:26:40 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Pair.hpp"
#include <memory>

#include <iostream>

enum e_color {red, black};
enum e_pos {left, right};

template <class T>
struct node
{
	public:
		T			data;
		node*		left;
		node*		right;
		node*		parent;
		e_color		color;		
	node(const T& val) : data(val), left(), right(), parent(), color(red) {}
};

template <class Key, class T, class Alloc = std::allocator<node<T> > >
class tree
{
	public:
		typedef	T											value_type;
		typedef	Key											key_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::size_type			size_type;
		
	public: //Make private after testing
		pointer				root_;
		size_type			size_;
		allocator_type		alloc_;

	public:	//Make private after testing
		pointer		allocNode(const value_type &val, pointer parent = NULL){
			pointer	node = alloc_.allocate(1);
			alloc_.construct(node, val);
			node->parent = parent;
			++size_;
			return (node);
		}

		void		destroy(pointer target){
			alloc_.destroy(target);
			alloc_.deallocate(target, 1);
			--size_;
		}
		
		void		leftRotate(pointer target){
			pointer temp = target->right;
			if (target->parent){
				(target->parent->left == target) ?
					target->parent->left = temp : target->parent->right = temp;
			}
			else
				root_ = temp;
			temp->parent = target->parent;
			target->right = temp->left;
			if (target->right)
				target->right->parent = target;
			temp->left = target;
			target->parent = temp;
		}

		void		rightRotate(pointer target){
			pointer temp = target->left;
			if (target->parent){
				(target->parent->left == target) ?
					target->parent->left = temp : target->parent->right = temp;
			}
			else
				root_ = temp;
			temp->parent = target->parent;
			target->left = temp->right;
			if (target->left)
				target->left->parent = target;
			temp->right = target;
			target->parent = temp;
		}

		void		balance(pointer target){
			while (target->parent){
				if (target->parent->color == black)
					return ;
				if (target->parent->parent->left == target->parent){
					if (target->parent->parent->right && target->parent->parent->right->color == red){
						target->parent->color = black;
						target->parent->parent->right->color = black;
						target->parent->parent->color = red;
						target = target->parent->parent;
						continue ;
					}
					if ((!target->parent->parent->right) || target->parent->parent->right->color == black){
						if (target->parent->right == target){
							leftRotate(target->parent);
							target = target->left;
							continue ;
						}
						target->parent->color = black;
						target->parent->parent->color = red;
						rightRotate(target->parent->parent);
						return ;
					}
				}
				if (target->parent->parent->right == target->parent){
					if (target->parent->parent->left && target->parent->parent->left->color == red){
						target->parent->color = black;
						target->parent->parent->left->color = black;
						target->parent->parent->color = red;
						target = target->parent->parent;
						continue ;
					}
					if ((!target->parent->parent->left) || target->parent->parent->left->color == black){
						if (target->parent->left == target){
							rightRotate(target->parent);
							target = target->right;
							continue ;
						}
						target->parent->color = black;
						target->parent->parent->color = red;
						leftRotate(target->parent->parent);
						return ;
					}
				}
			}
			if (!target->parent)
				target->color = black;
		}

		void		unblack(pointer target){
			pointer	parent = target->parent;
			while (target->parent){
				if (target->parent->left == target){
					if (target->parent->right->color == red){
						target->parent->color = red;
						target->parent->right->color = black;
						leftRotate(target->parent);
						continue ;
					}
					if (target->parent->right->right && target->parent->right->right->color == red){
						target->parent->right->right->color = target->parent->right->color;
						target->parent->right->color = target->parent->color;
						target->parent->color = black;
						leftRotate(target->parent);
						return ;
					}
					if (target->parent->right->left && target->parent->right->left->color == red){
						target->parent->right->left->color = target->parent->color;
						target->parent->color = black;
						rightRotate(target->parent->right);
						leftRotate(target->parent);
						return ;
					}
					target->parent->right->color = red;
					if (target->parent->color == red){
						target->parent->color = black;
						return ;
					}
					target = target->parent;
				}
				else {
					if (target->parent->left->color == red){
						target->parent->color = red;
						target->parent->left->color = black;
						rightRotate(target->parent);
						continue ;
					}
					if (target->parent->left->left && target->parent->left->left->color == red){
						target->parent->left->left->color = target->parent->left->color;
						target->parent->left->color = target->parent->color;
						target->parent->color = black;
						rightRotate(target->parent);
						return ;
					}
					if (target->parent->left->right && target->parent->left->right->color == red){
						target->parent->left->right->color = target->parent->color;
						target->parent->color = black;
						leftRotate(target->parent->left);
						rightRotate(target->parent);
						return ;
					}
					target->parent->left->color = red;
					if (target->parent->color == red){
						target->parent->color = black;
						return ;
					}
					target = target->parent;
				}
			}
			if (!target->parent)
				target->color = black;
		}

		void		remove(pointer target){
			if (target->left == NULL || target->right == NULL){
				if (target->left){
					if (target == root_)
						root_ = target->left;
					else
						(target->parent->left == target) ?
							target->parent->left = target->left : target->parent->right = target->left;
					target->left->parent = target->parent;
					if (target->color != target->left->color)
						target->left->color = black;
					else if (target->color == black && target->left->color == black)
						unblack(target->left);
				}
				else if (target->right){
					if (target == root_)
						root_ = target->right;
					else
						(target->parent->left == target) ?
							target->parent->left = target->right : target->parent->right = target->right;
					target->right->parent = target->parent;
					if (target->color != target->right->color)
						target->right->color = black;
					else if (target->color == black && target->right->color == black)
						unblack(target->right);
				}
				else {
					if (target == root_)
						root_ = NULL;
					else {
						if (target->color == black)
							unblack(target);
						(target->parent->left == target) ?
							target->parent->left = NULL : target->parent->right = NULL;
					}
				}
				destroy(target);
			}
			else {
				pointer	temp = target->left;
				while (temp->right)
					temp = temp->right;
				target->data = temp->data;
				remove(temp);
			}
		}

	public:
		tree() : root_(NULL) {} 
		~tree() {}
		void	insertNode(const value_type &val) {
			if (!root_){
				root_ = allocNode(val);
				root_->color = black;
				return ;
			}
			pointer	temp = root_;
			while ((val < temp->data && temp->left != NULL) || (val > temp->data && temp->right != NULL)){
				while (val < temp->data && temp->left != NULL)
					temp = temp->left;
				while (val > temp->data && temp->right != NULL)
					temp = temp->right;
			}
			if (val < temp->data){
				temp->left = allocNode(val, temp);
				balance(temp->left);
			}
			else {
				temp->right = allocNode(val, temp);
				balance(temp->right);
			}
		}

		void	printTree(){
			int	lines = 30;
			int	spaces = 20;

			if (root_){	//Level 1
				for (int i = 0; i < lines + spaces / 2; ++i)
					std::cout << "-";
				std::cout << root_->data.first << "." << root_->color;
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}
			else
				return ;
			{	//Level 2
				--lines; ++spaces;
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				(root_->left) ? std::cout << root_->left->data.first << "." << root_->left->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right) ? std::cout << root_->right->data.first << "." << root_->right->color : std::cout << "**";
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}
			{	//Level 3
				lines /= 1.2; spaces /= 2;
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				(root_->left && root_->left->left) ? std::cout << root_->left->left->data.first << "." << root_->left->left->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->left && root_->left->right) ? std::cout << root_->left->right->data.first << "." << root_->left->right->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->left) ? std::cout << root_->right->left->data.first << "." << root_->right->left->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->right) ? std::cout << root_->right->right->data.first << "." << root_->right->right->color : std::cout << "**";
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}
			{	//Level 4
				lines /= 1.1; spaces /= 2;
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				(root_->left && root_->left->left && root_->left->left->left) ? std::cout << root_->left->left->left->data.first << "." << root_->left->left->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->left && root_->left->left && root_->left->left->right) ? std::cout << root_->left->left->right->data.first << "." << root_->left->left->right->color
					: std::cout << "**";
				for (int i = 0; i < spaces - 2; ++i)
					std::cout << ' ';
				(root_->left && root_->left->right && root_->left->right->left) ? std::cout << root_->left->right->left->data.first << "." << root_->left->right->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->left && root_->left->right && root_->left->right->right) ? std::cout << root_->left->right->right->data.first << "." << root_->left->right->right->color
					: std::cout << "**";
				for (int i = 0; i < spaces - 2; ++i)
					std::cout << ' ';
				(root_->right && root_->right->left && root_->right->left->left) ? std::cout << root_->right->left->left->data.first << "." << root_->right->left->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->left && root_->right->left->right) ? std::cout << root_->right->left->right->data.first << "." << root_->right->left->right->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->right && root_->right->right->left) ? std::cout << root_->right->right->left->data.first << "." << root_->right->right->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->right && root_->right->right->right) ? std::cout << root_->right->right->right->data.first << "." << root_->right->right->right->color
					: std::cout << "**";
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}

		}
};