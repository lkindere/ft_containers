/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:49:44 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/11 00:55:25 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "RBTree.hpp"

#include <set>

namespace	ft {

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set
{
	public:
		typedef T									key_type;
		typedef T									value_type;
		typedef Compare								key_compare;
		typedef Compare								value_compare;
		typedef Alloc								allocator_type;
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::reference			reference;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef typename Alloc::const_reference		const_reference;
		typedef ptrdiff_t							difference_type;
		typedef	size_t					            size_type;

	public:
		typedef	tree<T>								tree;
		typedef	std::allocator<node<T> >			node_allocator;
		typedef	typename node_allocator::pointer	node_pointer;
		typedef typename tree::iterator				iterator;
		typedef typename tree::const_iterator		const_iterator;
		// typedef RITER<iterator>						reverse_iterator;
		// typedef RITER<const_iterator>				const_reverse_iterator;
	
	private:
		key_compare		comp;
		tree			base_;

	public:
		//																	Constructors

		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}

		// template <class InputIterator> set (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}

		// set (const set& x) {}

		// ~set() {}

		//set& operator= (const set& x) {}

		//																	Iterators
		
		iterator		begin() { return base_.begin(); }
		const_iterator 	begin() const { return base_.begin(); }
		iterator 		end() { return base_.end(); }
		const_iterator 	end() const { return base_.end(); }
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;


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

		// size_type erase (const value_type& val);
		// void erase (iterator first, iterator last);

		// void swap (set& x);

		void			clear() { base_.clear(); }


		//																	Observers

		key_compare		key_comp() const { return comp; }
		value_compare	value_comp() const { return comp; }
		
		
		//																	Operations

		iterator		find (const value_type& val){	//Has to be const but constructor is broken
			node_pointer n = base_.find(val);
			if (n)
				return (iterator(n));
			return end();
		}
		// size_type	count (const value_type& val) const;
		// iterator lower_bound (const value_type& val) const;
		// iterator upper_bound (const value_type& val) const;
		// pair<iterator,iterator> equal_range (const value_type& val) const;
		

		//																	Allocator

		// allocator_type get_allocator() const;

};





	
}