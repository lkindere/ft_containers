/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:49:44 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 15:38:19 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

#include "utils/RBTree.hpp"
#include "utils/Integral.hpp"

namespace	ft {

template <class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
class set
{
	public:
		typedef Key										key_type;
		typedef Key										value_type;
		typedef Compare									key_compare;
		typedef Compare									value_compare;
		typedef Alloc									allocator_type;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef typename Alloc::const_reference			const_reference;
		typedef ptrdiff_t								difference_type;
		typedef	size_t					            	size_type;

	public:
		typedef	tree<Key, Key, Compare, const Key>		rbtree;
		typedef typename rbtree::const_iterator			iterator;
		typedef typename rbtree::const_iterator			const_iterator;
		typedef typename rbtree::const_reverse_iterator	reverse_iterator;
		typedef typename rbtree::const_reverse_iterator	const_reverse_iterator;
	
	private:
		key_compare		comp;
		allocator_type	alloc;
		rbtree			base_;

	public:
		//																	Constructors

		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: comp(comp), alloc(alloc), base_() {}

		template <class InputIterator> set (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:	comp(comp), alloc(alloc), base_() {
			for (;first != last; ++first)
				insert(*first);
		}

		set (const set& x) : comp(x.comp), alloc(x.alloc), base_() {
			for (set::iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
		}

		~set() {}

		set& operator= (const set& x) {
			if (x == *this)
				return *this;
			base_.clear();
			comp = x.comp;
			for (set::iterator it = x.begin(); it != x.end(); ++it)
				insert(*it);
			return *this;
		}

		//																	Iterators
		
		iterator				begin() { return base_.begin(); }
		const_iterator 			begin() const { return base_.begin(); }
		iterator 				end() { return base_.end(); }
		const_iterator 			end() const { return base_.end(); }
		reverse_iterator 		rbegin() { return base_.rbegin(); }
		const_reverse_iterator	rbegin() const { return base_.rbegin(); }
		reverse_iterator 		rend() { return base_.rend(); }
		const_reverse_iterator 	rend() const { return base_.rend(); }


		//																	Capacity

		bool empty() const { return base_.empty(); }
		size_type size() const { return base_.size(); }
		size_type max_size() const { return base_.max_size(); }
		
		
		//																	Modifiers

		ft::pair<iterator,bool>	insert (const value_type& val) { return base_.insert(val); }

		iterator insert (iterator position, const value_type& val) {
			return (iterator(base_.insert(val, position.base()).first));
		}

		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last) {
			for (;first != last; ++first)
				base_.insert(*first);
		}

		void			erase (iterator position) { base_.remove(position.base()); }

		size_type		erase (const value_type& val) {
			iterator it = base_.find(val);
			if (it.end() != none)
				return 0;
			base_.remove(it.base());
			return 1;
		}

		void erase (iterator first, iterator last) {
			while (first != last)
				base_.remove(first++.base());
		}

		void swap (set& x){
			base_.swap(x.base_);
			Compare	temp_c = x.comp;
			x.comp = comp;
			comp = temp_c;
		}

		void			clear() { base_.clear(); }

		//																	Observers


		key_compare		key_comp() const { return comp; }
		value_compare	value_comp() const { return comp; }
		
		
		//																	Operations

		iterator		find (const value_type& val) const { return base_.find(val); }
		size_type		count (const value_type& val) const { return base_.count(val); }
		iterator		lower_bound (const value_type& val) const { return base_.lower_bound(val); }
		iterator		upper_bound (const value_type& val) const { return base_.upper_bound(val); }
		ft::pair<iterator,iterator>		equal_range (const value_type& val) const { return base_.equal_range(val); }
		
		//																	Allocator


		allocator_type get_allocator() const { allocator_type alloc; return alloc; }

		//																	Comparisons


		friend bool operator== (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
				if (lhs.size() != rhs.size())
					return false;
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}
		friend bool operator!= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
				if (lhs.size() != rhs.size())
					return true;
				return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

		friend bool operator< (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

		friend bool operator<= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
				return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
			}

		friend bool operator> (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
				return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
			}
			
		friend bool operator>= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
				return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

};

}