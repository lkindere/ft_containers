/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:12:27 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/11 03:43:18 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Pair.hpp"
#include <memory>
#include <functional>
#include "TreeIterator.hpp"



#include <iostream>

enum e_color {red, black};

template <class T>	//Key and data are the same
struct node
{
	public:
		T			data;
		node*		left;
		node*		right;
		node*		parent;
		e_color		color;
	
	public:
		node() : data(), left(), right(), parent(), color() {}
		node(const T& val) : data(val), left(), right(), parent(), color(red) {}

		T&	getKey() { return data; }
		T&	getData() { return data; }
};


template <class Key, class T = Key, class Compare = std::less<Key>, class Alloc = std::allocator<node<Key> > >
class tree
{
	public:
		typedef	T											value_type;
		typedef	Key											key_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::size_type			size_type;

		typedef	TreeIterator<key_type, pointer> 			iterator;
		typedef	TreeIterator<key_type, pointer> 			const_iterator;
		
	public: //Make private after testing
		pointer				root_;
		size_type			size_;
		allocator_type		alloc_;
	
	public:
		key_compare			comp;

	public:
	tree() : root_(NULL), size_(), alloc_() {} 
	~tree() {}

	iterator	begin() const {
		pointer	ptr = root_;
		if (!ptr)
			return end();
		while (ptr->left)
			ptr = ptr->left;
		return (iterator(ptr, false));
	};

	iterator	end() const {
		pointer	ptr = root_;
		while (ptr && ptr->right)
			ptr = ptr->right;
		return iterator(ptr, true);
	}

	key_compare	key_comp() const { return comp; }

	size_type	empty()	const { return (size_ == 0); }

	size_type	size() const { return size_; }

	size_type	max_size() const { return alloc_.max_size(); }

	void		clear() {
		while (root_)			//Probably not very efficient way to do it
			remove(root_);		//Could find a way without the black rebalancing
	}

	ft::pair<pointer, bool>	insert(const value_type &val, pointer hint = NULL) {
		if (hint)														//Add a hint check
			;
		if (!root_){
			root_ = allocNode(val);
			root_->color = black;
			return (ft::make_pair(root_, true));
		}
		pointer	temp = root_;
		while ((comp(val, temp->data) && temp->left != NULL) || (comp(temp->data, val) && temp->right != NULL)){
			while (comp(val, temp->data) && temp->left != NULL)
				temp = temp->left;
			while (comp(temp->data, val) && temp->right != NULL)
				temp = temp->right;
		}
		if ((!comp(val, temp->data)) && (!comp(temp->data, val)))
			return (ft::make_pair(temp, false));
		if (comp(val, temp->data)){
			temp->left = allocNode(val, temp);
			balance(temp->left);
			return (ft::make_pair(temp->left, true));
		}
		temp->right = allocNode(val, temp);
		balance(temp->right);
		return (ft::make_pair(temp->right, true));
	}

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

		iterator	find(const key_type& key) const {
			pointer	temp = root_;
			while (temp && (comp(key, temp->getKey()) || comp(temp->getKey(), key))){
				while (temp && comp(key, temp->getKey()))
					temp = temp->left;
				while (temp && comp(temp->getKey(), key))
					temp = temp->right;
			}
			if (temp)
				return (iterator(temp));
			return end();
		}

		size_type	count(const key_type& key) const {
			pointer	temp = root_;
			while (temp && (comp(key, temp->getKey()) || comp(temp->getKey(), key))){
				while (temp && comp(key, temp->getKey()))
					temp = temp->left;
				while (temp && comp(temp->getKey(), key))
					temp = temp->right;
			}
			if (temp)
				return 1;
			return 0;
		}

		iterator	lower_bound (const key_type& key) const {
			pointer	temp = root_;
			while (comp(key, temp->data) && temp->left)
				temp = temp->left;
			while (comp(temp->data, key) && temp->right)
				temp = temp->right;
			if (!comp(temp->data, key))
				return iterator(temp);
			if (temp->parent && !comp(temp->parent->data, key))
				return iterator(temp->parent);
			if (!comp(root_->data, key))
				return iterator(root_);
			return end();
		}

		iterator	upper_bound (const key_type& key) const {
			pointer	temp = root_;
			while (comp(key, temp->data) && temp->left)
				temp = temp->left;
			while (comp(temp->data, key) && temp->right)
				temp = temp->right;
			if (comp(key, temp->data))
				return iterator(temp);
			if (temp->parent && comp(key, temp->parent->data))
				return iterator(temp->parent);
			if (comp(key, root_->data))
				return iterator(root_);
			return end();
		}

		ft::pair<iterator,iterator>		equal_range (const value_type& val) const {
			return (ft::make_pair(lower_bound(val), upper_bound(val)));
		}

		void	printTree(){
			int	lines = 30;
			int	spaces = 20;

			if (root_){	//Level 1
				for (int i = 0; i < lines + spaces / 2; ++i)
					std::cout << "-";
				std::cout << root_->data << "." << root_->color;
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
				(root_->left) ? std::cout << root_->left->data << "." << root_->left->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right) ? std::cout << root_->right->data << "." << root_->right->color : std::cout << "**";
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}
			{	//Level 3
				lines /= 1.2; spaces /= 2;
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				(root_->left && root_->left->left) ? std::cout << root_->left->left->data << "." << root_->left->left->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->left && root_->left->right) ? std::cout << root_->left->right->data << "." << root_->left->right->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->left) ? std::cout << root_->right->left->data << "." << root_->right->left->color : std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->right) ? std::cout << root_->right->right->data << "." << root_->right->right->color : std::cout << "**";
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}
			{	//Level 4
				lines /= 1.1; spaces /= 2;
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				(root_->left && root_->left->left && root_->left->left->left) ? std::cout << root_->left->left->left->data << "." << root_->left->left->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->left && root_->left->left && root_->left->left->right) ? std::cout << root_->left->left->right->data << "." << root_->left->left->right->color
					: std::cout << "**";
				for (int i = 0; i < spaces - 2; ++i)
					std::cout << ' ';
				(root_->left && root_->left->right && root_->left->right->left) ? std::cout << root_->left->right->left->data << "." << root_->left->right->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->left && root_->left->right && root_->left->right->right) ? std::cout << root_->left->right->right->data << "." << root_->left->right->right->color
					: std::cout << "**";
				for (int i = 0; i < spaces - 2; ++i)
					std::cout << ' ';
				(root_->right && root_->right->left && root_->right->left->left) ? std::cout << root_->right->left->left->data << "." << root_->right->left->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->left && root_->right->left->right) ? std::cout << root_->right->left->right->data << "." << root_->right->left->right->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->right && root_->right->right->left) ? std::cout << root_->right->right->left->data << "." << root_->right->right->left->color
					: std::cout << "**";
				for (int i = 0; i < spaces; ++i)
					std::cout << ' ';
				(root_->right && root_->right->right && root_->right->right->right) ? std::cout << root_->right->right->right->data << "." << root_->right->right->right->color
					: std::cout << "**";
				for (int i = 0; i < lines; ++i)
					std::cout << "-";
				std::cout << std::endl;
			}

		}
};