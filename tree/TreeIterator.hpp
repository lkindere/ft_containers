/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:29:33 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/11 00:57:14 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Iterator.hpp"

template <typename T, typename N>
class TreeIterator
{		
	public:
		typedef	T											value_type;
		typedef	N											node_pointer;										
   		typedef typename std::bidirectional_iterator_tag	iterator_category;
		
	private:
		node_pointer	ptr_;
		bool			end_;
		
	public:
																			// Constructors
		TreeIterator(node_pointer root = nullptr, bool end = false) : ptr_(root), end_(end) {}

		// template <typename T>
		// TreeIterator(const TreeIterator<T>& iter) : ptr_(iter.base()), end_(iter.end()) {}

		~TreeIterator() {}
		
		// 																	// Operators
		TreeIterator&					operator=(const TreeIterator& iter) { ptr_ = iter.base(); end_ = iter.end(); return (*this); }

		bool							operator==(const TreeIterator& iter) const { return ((end_ == iter.end()) && ptr_ == iter.base()); }
		bool							operator!=(const TreeIterator& iter) const { return (!operator==(iter)); }
		
		const value_type				operator*()	const { return (ptr_->data); }
		// node_pointer							operator->() const { return &(ptr_->data); }

		TreeIterator&			operator++() {
			node_pointer	ptr = ptr_;
			node_pointer	old	= ptr;
			end_ = false;
			while (ptr->right == NULL || ptr->right == old){
				if (!ptr->parent){
					end_ = true;
					return (*this);
				}
				if (ptr->data < ptr->parent->data){
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
			if (end_){
				end_ = false;
				return (*this);
			}
			while (ptr->left == NULL || ptr->left == old){
				if (!ptr->parent){
					// end_ = true;
					return (*this);
				}
				if (ptr->parent->data < ptr->data){				//Tree compare? same for other 3
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
			end_ = false;
			while (ptr->right == NULL || ptr->right == old){
				if (!ptr->parent){
					end_ = true;
					return (it);
				}
				if (ptr->parent->data > ptr->data){
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
				end_ = false;
				return it;
			}
			while (ptr->left == NULL || ptr->left == old){
				if (!ptr->parent){
					// end_ = true;
					return it;
				}
				if (ptr->parent->data < ptr->data){
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

		node_pointer 	base() const { return ptr_; }
		bool	end() const { return end_; }
};
