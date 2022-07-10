/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:29:33 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/10 04:48:59 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Iterator.hpp"

namespace	ft {

template <typename _iter>
class TreeIterator
{		
	public:
		typedef	_iter*													node;
		typedef typename ft::iterator_traits<_iter>::value_type 		value_type;
		typedef typename ft::iterator_traits<_iter>::difference_type	difference_type;
		typedef typename ft::iterator_traits<_iter>::reference			reference;
		typedef typename ft::iterator_traits<_iter>::pointer			pointer;
   		typedef typename std::bidirectional_iterator_tag				iterator_category;
		
	private:
		node		ptr_;
		bool		end_;
		
	public:
		//																	Constructors
		TreeIterator(node root = nullptr, bool end = false) : ptr_(root), end_(end) {
			if (root){
				if (end)
					while (ptr_->right)
						ptr_ = ptr_->right;
				else
					while (ptr_->left)
						ptr_ = ptr_->left;
			}
		}

		template <typename T>
		TreeIterator(const TreeIterator<T>& iter) : ptr_(iter.base()), end_(iter.end()) {}

		~TreeIterator() {}
		
		//																	Operators
		template <typename T>
		TreeIterator<pointer>&			operator=(const TreeIterator<T>& iter) { ptr_ = iter.base(); end_ = iter.end(); return (*this); }

		template <typename Iter>
		bool							operator==(const TreeIterator<Iter>& iter) const { return ((end_ && iter.end()) || ptr_ == iter.base()); }
		template <typename Iter>
		bool							operator!=(const TreeIterator<Iter>& iter) const { return (!operator==(iter)); }
		
		value_type&						operator*() { return (ptr_->data); }
		const value_type&				operator*()	const { return (ptr_->data); }
		pointer							operator->() const { return &(ptr_->data); }

		TreeIterator<_iter>&			operator++() {
			node	ptr = ptr_;
			node	old	= ptr;
			end_ = false;
			while (ptr->right == NULL || ptr->right == old){
				if (!ptr->parent){
					end_ = true;
					return (*this);
				}
				if (ptr->parent > ptr){
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

		TreeIterator<_iter>&			operator--() {
			node	ptr = ptr_;
			node	old	= ptr;
			if (end_){
				end_ = false;
				return (*this);
			}
			while (ptr->left == NULL || ptr->left == old){
				if (!ptr->parent){
					// end_ = true;
					return (*this);
				}
				if (ptr->parent < ptr){
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

		TreeIterator<_iter>			operator++(int) {
			TreeIterator<_iter>	it = (*this);
			node	ptr = ptr_;
			node	old	= ptr;
			end_ = false;
			while (ptr->right == NULL || ptr->right == old){
				if (!ptr->parent){
					end_ = true;
					return (it);
				}
				if (ptr->parent > ptr){
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

		TreeIterator<_iter>			operator--(int) {
			TreeIterator<_iter>	it = (*this);
			node	ptr = ptr_;
			node	old	= ptr;
			if (end_){
				end_ = false;
				return it;
			}
			while (ptr->left == NULL || ptr->left == old){
				if (!ptr->parent){
					// end_ = true;
					return it;
				}
				if (ptr->parent < ptr){
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

		node 	base() const { return ptr_; }
		bool	end() const { return end_; }
};

}