/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:01:44 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/07 15:10:57 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>
#include "Pair.hpp"
#include <memory>
#include <functional>
#include <map>

#include <iostream>

namespace ft {

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
		// typedef typename allocator_type::reference			reference;
		// typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		// typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		// typedef typename allocator_type::difference_type	difference_type;
		
	public: //Make private after testing
		pointer				root_;
		size_type			size_;
		allocator_type		alloc_;

	public:	//Make private after testing
		pointer		allocNode(const value_type &val, pointer parent = nullptr){
			pointer	node = alloc_.allocate(1);
			alloc_.construct(node, val);
			node->parent = parent;
			return (node);
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
			if (!target->parent){
				target->color = black;
				return ;
			}
			if (target->parent->color == black)
				return ;
			if (target->parent->parent->left == target->parent){	//Parent is left child
				if (target->parent->parent->right && target->parent->parent->right->color == red){	//Uncle is also red	
					target->parent->color = black;
					target->parent->parent->right->color = black;
					target->parent->parent->color = red;
					balance(target->parent->parent);
					return ;
				}
				if ((!target->parent->parent->right) || target->parent->parent->right->color == black){	//Uncle is black
					if (target->parent->right == target){
						leftRotate(target->parent);					//Switch to left
						balance(target->left);
						return ;
					}
					target->parent->color = black;					//Target is left child
					target->parent->parent->color = red;
					rightRotate(target->parent->parent);
					return ;
				}
			}
			if (target->parent->parent->right == target->parent){	//Parent is right child
				if (target->parent->parent->left && target->parent->parent->left->color == red){	//Uncle is also red	
					target->parent->color = black;
					target->parent->parent->left->color = black;
					target->parent->parent->color = red;
					balance(target->parent->parent);
					return ;
				}
				if ((!target->parent->parent->left) || target->parent->parent->left->color == black){	//Uncle is black
					if (target->parent->left == target){
						rightRotate(target->parent);					//Switch to left
						balance(target->right);
						return ;
					}			//Target is right child
					target->parent->color = black;					//Target is left child
					target->parent->parent->color = red;
					leftRotate(target->parent->parent);
					return ;
				}
			}
		}

	public:
		tree() : root_(nullptr) {} 
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

		value_type	getNode() {
			return root_->data;
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

// template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
// class map
// {
// 	public:
// 		typedef Key											key_type;
// 		typedef T											mapped_type;
// 		typedef pair<const key_type, mapped_type>			value_type;
// 		typedef Compare										key_compare;
// 		typedef Alloc										allocator_type;
// 		typedef typename allocator_type::reference			reference;
// 		typedef typename allocator_type::const_reference	const_reference;
// 		typedef typename allocator_type::pointer			pointer;
// 		typedef typename allocator_type::const_pointer		const_pointer;
// 		typedef typename allocator_type::size_type			size_type;
// 		typedef typename allocator_type::difference_type	difference_type;

// 		// typedef Bidir iter								iterator;
// 		// typedef Bidir iter								const_iterator;
// 		// typedef std::reverse_iterator<iterator>			reverse_iterator;
// 		// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

// 	private:
// 		tree<key_type, value_type>		tree_;
// 		allocator_type					alloc_;
		
// 	public:

// 		//																			Constructors

// 		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
// 			: alloc_(alloc) {}
// 		// template <class InputIterator>
// 		// map (InputIterator first, InputIterator last,
// 		// 	const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
// 		// map (const map& x);
// 		~map() {}
	
// 		// map&			operator= (const map& x);
// 		// mapped_type&	operator[] (const key_type& k); 
		
// 		//																			Iterators

// 		// iterator begin() { return iterator(data_); }
// 		// iterator end() { return iterator(&data_[size_]); }

// 		// const_iterator begin() const { return iterator(data_); }
// 		// const_iterator end() const { return iterator(&data_[size_]); }

// 		// reverse_iterator rbegin() { return end(); }
//       	// reverse_iterator rend() { return begin(); }

// 		// const_reverse_iterator rbegin() const { return end(); }
// 		// const_reverse_iterator rend() const { return begin(); }

// 		//																			Capacity

// 		// bool empty() const { return (size_ == 0); }
// 		// size_type size() const { return size_; }
// 		// size_type max_size() const { return alloc_.max_size(); }


// 		//																			Modifiers

// 		pair<iterator, bool>		insert (const value_type& val) {
// 		void	insert (const value_type& val) {
// 			tree_.insertNode(val);
// 		}

// 		value_type	getRoot() {
// 			return (tree_.getNode());
// 		}

// 		// iterator				insert (iterator position, const value_type& val);

// 		// template <class InputIterator>
// 		// void					insert (InputIterator first, InputIterator last);

// 		// void					erase (iterator position);

// 		// size_type				erase (const key_type& k);

// 		// void					erase (iterator first, iterator last);
		
// 		// void					swap (map& x);

// 		// void					clear();


// 		//																			Observers

// 		// key_compare				key_comp() const;

// 		// value_compare			value_comp() const;

		
// 		//																			Operations

// 		// iterator				find (const key_type& k);

// 		// const_iterator			find (const key_type& k) const;

// 		// size_type				count (const key_type& k) const;

// 		// iterator				lower_bound (const key_type& k);

// 		// const_iterator			lower_bound (const key_type& k) const;

// 		// iterator				upper_bound (const key_type& k);

// 		// const_iterator			upper_bound (const key_type& k) const;

// 		// pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;

// 		// pair<iterator,iterator>				equal_range (const key_type& k);


// 		//																			Allocator
		
// 		allocator_type get_allocator() const { return alloc_; }

// };

}
