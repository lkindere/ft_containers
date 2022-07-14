/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:12:27 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/14 17:49:51 by lkindere         ###   ########.fr       */
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
};

template <class Key, class Data, class Compare, class Ret = Data, class Con = Ret>
class tree
{
	public:
		typedef Key											key_type;
		typedef	Data										data_type;
		typedef Compare										key_compare;
		typedef	Ret											value_type;
		typedef	Con											const_type;
		typedef	typename std::allocator<node<Ret> >			allocator_type;
		typedef	typename allocator_type::pointer			pointer;
		typedef typename allocator_type::size_type			size_type;
		
		typedef	TreeIterator<value_type, pointer, Compare> 	iterator;
		typedef	ConstTreeIterator<const_type, pointer, Compare> const_iterator;
		typedef TreeRevIterator<iterator>					reverse_iterator;
		typedef TreeRevIterator<const_iterator>				const_reverse_iterator;
	
	public:
		Compare				comp;

	public: //Make private after testing
		pointer				root_;
		size_type			size_;
		allocator_type		alloc_;

	public:
	tree() : root_(NULL), size_(), alloc_() {} 
	tree(const tree& t) : root_(t.root_), size_(t.size_), alloc_(t.alloc_) {}
	~tree() {}

	iterator	begin() const {
		pointer	ptr = root_;
		if (!ptr)
			return end();
		while (ptr->left)
			ptr = ptr->left;
		return (iterator(ptr, none));
	};

	// const_iterator	begin() {
	// 	pointer	ptr = root_;
	// 	if (!ptr)
	// 		return end();
	// 	while (ptr->left)
	// 		ptr = ptr->left;
	// 	return (iterator(ptr, none));
	// };

	iterator	end() const {
		pointer	ptr = root_;
		while (ptr && ptr->right)	
			ptr = ptr->right;
		return iterator(ptr, is_end);
	}

	// const_iterator	end() {
	// 	pointer	ptr = root_;
	// 	while (ptr && ptr->right)	
	// 		ptr = ptr->right;
	// 	return iterator(ptr, is_end);
	// }

	reverse_iterator	rbegin() const { return (reverse_iterator(end())); }
	// const_reverse_iterator	rbegin() { return (reverse_iterator(end())); }
	reverse_iterator	rend() const { return (reverse_iterator(begin())); }
	// const_reverse_iterator	rend const() const { return (reverse_iterator(begin())); }

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
			temp = temp->left;
			balance(temp);
			return (ft::make_pair(temp, true));
		}
		temp->right = allocNode(val, temp);
		temp = temp->right;
		balance(temp);
		return (ft::make_pair(temp, true));
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
				consts_are_killing_me(&target, temp);
				remove(temp);
			}

		}

		void consts_are_killing_me(pointer *target, pointer temp) {
			pointer	left = (*target)->left;
			pointer right = (*target)->right;
			pointer parent = (*target)->parent;
			e_color	color = (*target)->color;
			alloc_.construct(*target, temp->data);
			(*target)->left = left;
			(*target)->right = right;
			(*target)->parent = parent;
			(*target)->color = color;
		}

		iterator	find(const key_type& key) const {
			pointer	temp = root_;
			while (temp && (comp(key, temp->data) || comp(temp->data, key))){
				while (temp && comp(key, temp->data))
					temp = temp->left;
				while (temp && comp(temp->data, key))
					temp = temp->right;
			}
			if (temp)
				return (iterator(temp));
			return end();
		}

		size_type	count(const key_type& key) const {
			pointer	temp = root_;
			while (temp && (comp(key, temp->data) || comp(temp->data, key))){
				while (temp && comp(key, temp->data))
					temp = temp->left;
				while (temp && comp(temp->data, key))
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
			if (temp->left && !comp(temp->left->data, key))
				return iterator(temp->left);
			if (!comp(temp->data, key))
				return iterator(temp);
			if (temp->parent && !comp(temp->parent->data, key))	//Useless?
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
			if (temp->left && comp(key, temp->left->data))
				return iterator(temp->left);
			if (comp(key, temp->data))
				return iterator(temp);
			if (temp->parent && comp(key, temp->parent->data)) //Useless?
				return iterator(temp->parent);
			if (comp(key, root_->data))
				return iterator(root_);
			return end();
		}

		ft::pair<iterator,iterator>		equal_range (const key_type& val) const {
			return (ft::make_pair(lower_bound(val), upper_bound(val)));
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
