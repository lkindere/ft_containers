/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:52:58 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/02 22:55:43 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Iterator.hpp"

namespace	ft {
template <typename T>
class VectorIterator
{		
	public:
   		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<T>::value_type 		value_type;
		typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T>::reference			reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		
	public:
		pointer		ptr_;
	
	public:
		//																	Constructors
		VectorIterator(pointer ptr = nullptr) { ptr_ = ptr; }
		template <typename Iter>
		VectorIterator(const VectorIterator<Iter>& iter) { ptr_ = iter.ptr_; }
		~VectorIterator() {}
		
		//																	Operators
		VectorIterator<pointer>&		operator=(pointer ptr) { ptr_ = ptr; return (*this); }

		template <typename Iter>
		bool							operator==(const VectorIterator<Iter>& iter) const { return (ptr_ == iter.ptr_); }
		template <typename Iter>
		bool							operator!=(const VectorIterator<Iter>& iter) const { return (ptr_ != iter.ptr_); }
		
		value_type&						operator*()	const { return (*ptr_); }
		pointer							operator->() const { return &(operator*()); }
		value_type&						operator[](difference_type val) const { return (ptr_[val]); }

		VectorIterator<pointer>&		operator++() { ++ptr_; return (*this); }
		VectorIterator<pointer>&		operator--() { --ptr_; return (*this); }
		VectorIterator<pointer>			operator++(int) { VectorIterator<pointer>	it = (*this); ++ptr_; return (it); }
		VectorIterator<pointer>			operator--(int) { VectorIterator<pointer>	it = (*this); --ptr_; return (it); }

		VectorIterator<pointer>&		operator+=(difference_type val) { ptr_ += val; return (*this);}
		VectorIterator<pointer>&		operator-=(difference_type val) { ptr_ -= val; return (*this);}

		VectorIterator<pointer>			operator+(difference_type val) const { return VectorIterator<pointer>(ptr_ + val); }
		VectorIterator<pointer>			operator-(difference_type val) const { return VectorIterator<pointer>(ptr_ - val); }
		difference_type					operator-(const	VectorIterator<pointer>& iter) const { return std::distance(iter.ptr_, ptr_); }

		template <typename Iter>
		bool							operator<(const VectorIterator<Iter>& iter) const { return (ptr_ < iter.ptr_); }
		template <typename Iter>
		bool							operator>(const VectorIterator<Iter>& iter) const { return (ptr_ > iter.ptr_); }
		template <typename Iter>
		bool							operator<=(const VectorIterator<Iter>& iter) const { return (ptr_ <= iter.ptr_); }
		template <typename Iter>
		bool							operator>=(const VectorIterator<Iter>& iter) const { return (ptr_ >= iter.ptr_); }

		friend	VectorIterator<pointer>
			operator+(difference_type val, const VectorIterator<pointer>& iter) { return VectorIterator<pointer>(iter.ptr_ + val); }

};

template <typename T>
class VectorRevIterator
{
	public:
	typedef typename std::iterator_traits<T>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<T>::value_type 		value_type;
	typedef typename std::iterator_traits<T>::difference_type	difference_type;
	typedef typename std::iterator_traits<T>::reference			reference;
	typedef typename std::iterator_traits<T>::pointer			pointer;

	private:
		pointer		ptr_;
	
	public:
		//																	Constructors
		VectorRevIterator(pointer ptr = nullptr) { ptr_ = ptr; }
		template <typename Iter>
		VectorRevIterator(const VectorIterator<Iter>& iter) { ptr_ = iter.ptr_; }
		template <typename Iter>
		VectorRevIterator(const VectorRevIterator<Iter>& iter) { ptr_ = iter.ptr_; }
		~VectorRevIterator() {}
		
		//																	Operators

		VectorRevIterator<pointer>&		operator=(pointer ptr) { ptr_ = ptr; return (*this); }

		template <typename Iter>
		bool							operator==(const VectorRevIterator<Iter>& iter) const { return (ptr_ == iter.ptr_); }
		template <typename Iter>
		bool							operator!=(const VectorRevIterator<Iter>& iter) const { return (ptr_ != iter.ptr_); }
		
		value_type&						operator*() { return (*ptr_); }
		const value_type&				operator*()	const { return (*ptr_); }
		const pointer					operator->() const { return ptr_; }
		pointer							operator->() { return ptr_; }
		value_type&						operator[](difference_type val) const { return (ptr_[-val]); }

		VectorRevIterator<pointer>&		operator++() { --ptr_; return (*this); }
		VectorRevIterator<pointer>&		operator--() { ++ptr_; return (*this); }
		VectorRevIterator<pointer>		operator++(int) { VectorRevIterator<pointer>	it = (*this); --ptr_; return (it); }
		VectorRevIterator<pointer>		operator--(int) { VectorRevIterator<pointer>	it = (*this); ++ptr_; return (it); }

		VectorRevIterator<pointer>&		operator+=(difference_type val) { ptr_ -= val; return (*this);}
		VectorRevIterator<pointer>&		operator-=(difference_type val) { ptr_ += val; return (*this);}

		VectorRevIterator<pointer>		operator+(difference_type val) const { return VectorRevIterator<pointer>(ptr_ - val); }
		VectorRevIterator<pointer>		operator-(difference_type val) const { return VectorRevIterator<pointer>(ptr_ + val); }
		difference_type					operator-(const	VectorRevIterator<pointer>& iter) const { return std::distance(iter.ptr_, ptr_); }

		template <typename Iter>
		bool							operator<(const VectorRevIterator<Iter>& iter) const { return (ptr_ > iter.ptr_); }
		template <typename Iter>
		bool							operator>(const VectorRevIterator<Iter>& iter) const { return (ptr_ < iter.ptr_); }
		template <typename Iter>
		bool							operator<=(const VectorRevIterator<Iter>& iter) const { return (ptr_ >= iter.ptr_); }
		template <typename Iter>
		bool							operator>=(const VectorRevIterator<Iter>& iter) const { return (ptr_ <= iter.ptr_); }

		friend	VectorRevIterator<pointer>
			operator+(difference_type val, const VectorRevIterator<pointer>& iter) { return VectorRevIterator<pointer>(iter.ptr_ - val); }

};

}
