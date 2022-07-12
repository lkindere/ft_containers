/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:29:33 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/12 17:46:59 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "../Iterator.hpp"

enum	e_end {none = 0, is_end, is_rend};

template <typename T, typename N, typename Compare>
class TreeIterator
{		
	public:
		typedef	T											value_type;
		typedef	N											node_pointer;										
   		typedef typename std::bidirectional_iterator_tag	iterator_category;
		
	private:
		Compare			comp;
		node_pointer	ptr_;
		e_end			end_;
		
	public:
																			// Constructors
		TreeIterator(node_pointer root = nullptr, e_end end = none) : ptr_(root), end_(end) {}

		// template <typename T>
		TreeIterator(const TreeIterator<T, N, Compare>& iter) : ptr_(iter.base()), end_(iter.end()) {}

		~TreeIterator() {}
		
		// 																	// Operators
		TreeIterator&					operator=(const TreeIterator& iter) { ptr_ = iter.base(); end_ = iter.end(); return (*this); }

		bool							operator==(const TreeIterator& iter) const {
			return ((end_ && end_ == iter.end_) || (end_ == 0 && iter.end() == 0 && ptr_ == iter.base()));
		}
		bool							operator!=(const TreeIterator& iter) const { return (!operator==(iter)); }
		
		const value_type&				operator*()	const { return (ptr_->data); }
		const value_type*				operator->() const { return &ptr_->data; }

		TreeIterator&			operator++() {
			node_pointer	ptr = ptr_;
			node_pointer	old	= ptr;
			if (end_ == is_rend){
				end_ = none;
				return (*this);
			}
			while (ptr->right == NULL || ptr->right == old){
				if (!ptr->parent){
					end_ = is_end;
					return (*this);
				}
				if (comp(ptr->data, ptr->parent->data)){
					ptr_ = ptr->parent;
					return (*this);
				}
				old = ptr;
				ptr = ptr->parent;
			}
			ptr = ptr->right;
			while (ptr->left)
				ptr = ptr->left;
			ptr_ = ptr;
			return (*this);
		}

		TreeIterator&			operator--() {
			node_pointer	ptr = ptr_;
			node_pointer	old	= ptr;
			if (end_ == is_end){
				end_ = none;
				return (*this);
			}
			while (ptr->left == NULL || ptr->left == old){
				if (!ptr->parent){
					end_ = is_rend;
					return (*this);
				}
				if (comp(ptr->parent->data, ptr->data)){
					ptr_ = ptr->parent;
					return (*this);
				}
				old = ptr;
				ptr = ptr->parent;
			}
			ptr = ptr->left;
			while (ptr->right)
				ptr = ptr->right;
			ptr_ = ptr;
			return (*this);
		}

		TreeIterator			operator++(int) {
			TreeIterator	it = (*this);
			node_pointer	ptr = ptr_;
			node_pointer	old	= ptr;
			if (end_ == is_rend){
				end_ = none;
				return (*this);
			}
			while (ptr->right == NULL || ptr->right == old){
				if (!ptr->parent){
					end_ = is_end;
					return (it);
				}
				if (comp(ptr->data, ptr->parent->data)){
					ptr_ = ptr->parent;
					return (it);
				}
				old = ptr;
				ptr = ptr->parent;
			}
			ptr = ptr->right;
			while (ptr->left)
				ptr = ptr->left;
			ptr_ = ptr;
			return (it);
		}

		TreeIterator			operator--(int) {
			TreeIterator	it = (*this);
			node_pointer	ptr = ptr_;
			node_pointer	old	= ptr;
			if (end_){
				end_ = none;
				return it;
			}
			while (ptr->left == NULL || ptr->left == old){
				if (!ptr->parent){
					end_ = is_rend;
					return it;
				}
				if (comp(ptr->parent->data, ptr->data)){
					ptr_ = ptr->parent;
					return it;
				}
				old = ptr;
				ptr = ptr->parent;
			}
			ptr = ptr->left;
			while (ptr->right)
				ptr = ptr->right;
			ptr_ = ptr;
			return it;
		}

		node_pointer	base() const { return ptr_; }
		e_end			end() const { return end_; }
};

template <typename _iter>
class TreeRevIterator
{		
	public:
		typedef	typename _iter::value_type					value_type;
		typedef	typename _iter::node_pointer				node_pointer;										
   		typedef typename std::bidirectional_iterator_tag	iterator_category;
		
	private:
		_iter	current;
		
	public:
																			// Constructors
		TreeRevIterator(_iter iter = NULL) : current(iter) {}

		template <typename T>
		TreeRevIterator(const TreeRevIterator<T>& iter) : current(iter.base()) {}

		~TreeRevIterator() {}
		
																			// Operators
		TreeRevIterator&				operator=(const TreeRevIterator& iter) {
			current = iter.base(); return (*this);
		}

		bool							operator==(const TreeRevIterator& iter) const {
			return (iter.base() == current.base());
		}
		bool							operator!=(const TreeRevIterator& iter) const { return (!operator==(iter)); }
		
		const value_type&				operator*() const {
			_iter it(current); return (*--it);
		}

		const value_type*				operator->() const {
			_iter it(current); return &(*--it);
		}

		TreeRevIterator&				operator++() { --current; return (*this); }

		TreeRevIterator&				operator--() { ++current; return (*this); }

		TreeRevIterator					operator++(int) { TreeRevIterator it(*this); --current; return (it); }

		TreeRevIterator					operator--(int) { TreeRevIterator it(*this); ++current; return (it); }

		_iter		base() const { return current; }
		e_end		end() const	{ return current.end(); }
};
