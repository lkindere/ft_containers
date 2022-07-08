/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:01:44 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/08 23:17:11 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "RBTree.hpp"

#include <utility>
#include "Pair.hpp"
#include <memory>
#include <functional>
#include <map>

#include <iostream>

namespace ft {

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
