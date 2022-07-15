/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:01:44 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 12:15:48 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <functional>

#include "RBTree.hpp"
#include "../Pair.hpp"
#include "../Integral.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
class map
{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<key_type, mapped_type>					value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;

	private:
		class value_compare
		{
			public:
				Compare		comp;
			
			public:
				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
				bool operator() (const key_type& k, const value_type& y) const { return comp(k, y.first); }
				bool operator()	(const value_type&x, const key_type& k) const { return comp(x.first, k); }
				bool operator()	(const key_type& k1, const key_type& k2) const { return comp(k1, k2); }
		};
		
	private:
		typedef	pair<const key_type, mapped_type>			value_pair;
		typedef	const pair<const key_type, mapped_type>		const_pair;
		
	public:
		typedef	std::allocator<node<value_type> >			node_allocator;
		typedef	typename node_allocator::pointer			node_pointer;
		typedef	tree<key_type, value_type,
				value_compare, value_pair, const_pair>		rbtree;
		typedef typename rbtree::iterator					iterator;
		typedef typename rbtree::const_iterator				const_iterator;
		typedef typename rbtree::reverse_iterator			reverse_iterator;
		typedef typename rbtree::const_reverse_iterator		const_reverse_iterator;

		
	private:
		key_compare		comp;
		value_compare	vcomp;
		
	private:			//Private after testing
		allocator_type	alloc;
		rbtree			base_;
		
	public:

		//																			Constructors

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: comp(comp), alloc(alloc), base_() {}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:	comp(comp), alloc(alloc), base_() {
			for (;first != last; ++first)
				insert(*first);
		}
		
		map (const map& x) {
			for (map::const_iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
		}

		~map() {}
	
		map&			operator= (const map& x) {
			if (x == *this)
				return *this;
			base_.clear();
			for (map::const_iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
			return *this;
		}
		
		mapped_type&	operator[] (const key_type& k) {
			iterator it = insert(ft::make_pair(k, mapped_type())).first;
			return (*it).second;
		}
		
		//																			Iterators

		iterator				begin() { return base_.begin(); }
		const_iterator 			begin() const { return base_.begin(); }
		iterator 				end() { return base_.end(); }
		const_iterator 			end() const { return base_.end(); }
		reverse_iterator 		rbegin() { return base_.rbegin(); }
		const_reverse_iterator	rbegin() const { return base_.rbegin(); }
		reverse_iterator 		rend() { return base_.rend(); }
		const_reverse_iterator 	rend() const { return base_.rend(); }

		// 																			Capacity

		bool 					empty() const { return base_.empty(); }
		size_type 				size() const { return base_.size(); }
		size_type 				max_size() const { return base_.max_size(); }


		//																			Modifiers

		pair<iterator, bool>	insert (const value_type& val) { return base_.insert(val); }

		iterator				insert (iterator position, const value_type& val) {
			return (iterator(base_.insert(val, position.base()).first));
		}

		template <class InputIterator>
		void					insert (InputIterator first, InputIterator last) {
			for (;first != last; ++first)
				base_.insert(*first);
		}

		void					erase (iterator position) { base_.remove(position.base()); }

		size_type				erase (const key_type& k) {
			iterator it = base_.find(k);
			if (it.end() != none)
				return 0;
			base_.remove(it.base());
			return 1;
		}

		void					erase (iterator first, iterator last) {
			while (first != last)
				base_.remove(first++.base());
		}
		
		void					swap (map& x) {
			base_.swap(x.base_);
			Compare	temp_c = x.comp;
			x.comp = comp;
			comp = temp_c;
		}

		void					clear()  { base_.clear(); }

		//																			Observers

		key_compare				key_comp() const { return comp; }
		value_compare			value_comp() const { return vcomp; }

		//																			Operations

		iterator				find (const key_type& k) { return base_.find(k); }
		const_iterator			find (const key_type& k) const { return base_.find(k); }

		size_type				count (const key_type& k) const { return base_.count(k); }

		iterator				lower_bound (const key_type& k) { return base_.lower_bound(k); }
		const_iterator			lower_bound (const key_type& k) const { return base_.lower_bound(k); }
		iterator				upper_bound (const key_type& k) { return base_.upper_bound(k); }
		const_iterator			upper_bound (const key_type& k) const { return base_.upper_bound(k); }

		ft::pair<iterator,iterator>				equal_range (const key_type& k) { return base_.equal_range(k); }
		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const { return base_.equal_range(k); }


		//																			Allocator
		
		allocator_type get_allocator() const { return alloc; }


		//																			Comparisons

		friend bool operator== (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
				if (lhs.size() != rhs.size())
					return false;
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}
		friend bool operator!= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
				if (lhs.size() != rhs.size())
					return true;
				return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

		friend bool operator< (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

		friend bool operator<= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
				return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
			}

		friend bool operator> (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
				return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
			}
			
		friend bool operator>= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
				return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

};

}
