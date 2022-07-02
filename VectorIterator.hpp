/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:52:58 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/02 16:47:01 by lkindere         ###   ########.fr       */
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
		VectorIterator(const VectorIterator<Iter>& iter) : ptr_(iter.ptr_) { }
		~VectorIterator() {}
		
		//																	Operators
		VectorIterator<pointer>&		operator=(pointer ptr) { ptr_ = ptr; return (*this); }

		bool							operator==(const VectorIterator<pointer>& iter) const { return (ptr_ == iter.ptr_); }
		bool							operator!=(const VectorIterator<pointer>& iter) const { return (ptr_ != iter.ptr_); }
		
		value_type&						operator*() { return (*ptr_); }
		const value_type&				operator*()	const { return (*ptr_); }
		pointer							operator->() const { return ptr_; }
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

		bool							operator<(VectorIterator<pointer>& iter) const { return (ptr_ < iter.ptr_); }
		bool							operator>(VectorIterator<pointer>& iter) const { return (ptr_ > iter.ptr_); }
		bool							operator<=(VectorIterator<pointer>& iter) const { return (ptr_ <= iter.ptr_); }
		bool							operator>=(VectorIterator<pointer>& iter) const { return (ptr_ >= iter.ptr_); }

		friend	VectorIterator<pointer>
			operator+(difference_type val, const VectorIterator<T>& iter) { return VectorIterator<pointer>(iter.ptr_ + val); }

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

		VectorIterator<pointer>&		operator=(pointer ptr) { ptr_ = ptr; return (*this); }

		bool							operator==(const VectorIterator<pointer>& iter) const { return (ptr_ == iter.ptr_); }
		bool							operator!=(const VectorIterator<pointer>& iter) const { return (ptr_ != iter.ptr_); }
		
		value_type&						operator*() { return (*ptr_); }
		const value_type&				operator*()	const { return (*ptr_); }
		pointer							operator->() const { return ptr_; }
		value_type&						operator[](difference_type val) const { return (ptr_[-val]); }

		VectorIterator<pointer>&		operator++() { --ptr_; return (*this); }
		VectorIterator<pointer>&		operator--() { ++ptr_; return (*this); }
		VectorIterator<pointer>			operator++(int) { VectorIterator<pointer>	it = (*this); --ptr_; return (it); }
		VectorIterator<pointer>			operator--(int) { VectorIterator<pointer>	it = (*this); ++ptr_; return (it); }

		VectorIterator<pointer>&		operator+=(difference_type val) { ptr_ -= val; return (*this);}
		VectorIterator<pointer>&		operator-=(difference_type val) { ptr_ += val; return (*this);}

		VectorIterator<pointer>			operator+(difference_type val) const { return VectorIterator<pointer>(ptr_ - val); }
		VectorIterator<pointer>			operator-(difference_type val) const { return VectorIterator<pointer>(ptr_ + val); }
		difference_type					operator-(const	VectorIterator<pointer>& iter) const { return std::distance(iter.ptr_, ptr_); }

		bool							operator<(VectorIterator<pointer>& iter) const { return (ptr_ > iter.ptr_); }
		bool							operator>(VectorIterator<pointer>& iter) const { return (ptr_ < iter.ptr_); }
		bool							operator<=(VectorIterator<pointer>& iter) const { return (ptr_ >= iter.ptr_); }
		bool							operator>=(VectorIterator<pointer>& iter) const { return (ptr_ <= iter.ptr_); }

		friend	VectorIterator<pointer>
			operator+(difference_type val, const VectorIterator<T>& iter) { return VectorIterator<pointer>(iter.ptr_ - val); }

};

}
