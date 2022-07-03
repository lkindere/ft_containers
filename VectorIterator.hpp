/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:52:58 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/03 23:55:59 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Iterator.hpp"

namespace	ft {

template <typename _iter>
class VectorRevIterator;

template <typename _iter>
class VectorIterator
{		
	public:
   		typedef typename ft::iterator_traits<_iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<_iter>::value_type 		value_type;
		typedef typename ft::iterator_traits<_iter>::difference_type	difference_type;
		typedef typename ft::iterator_traits<_iter>::reference			reference;
		typedef typename ft::iterator_traits<_iter>::pointer			pointer;
		
	private:
		_iter		ptr_;
	
	public:
		//																	Constructors
		VectorIterator(pointer ptr = nullptr) : ptr_(ptr) {}

		template <typename T>
		VectorIterator(const VectorIterator<T>& iter) : ptr_(iter.base()) {}

		// template <typename T>
		// VectorIterator(const VectorRevIterator<T>& iter) {}
		~VectorIterator() {}
		
		//																	Operators
		template <typename T>
		VectorIterator<pointer>&		operator=(const VectorIterator<T>& iter) { ptr_ = iter.base(); return (*this); }

		template <typename Iter>
		bool							operator==(const VectorIterator<Iter>& iter) const { return (ptr_ == iter.base()); }
		template <typename Iter>
		bool							operator!=(const VectorIterator<Iter>& iter) const { return (ptr_ != iter.base()); }
		
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
		difference_type					operator-(const	VectorIterator<pointer>& iter) const { return std::distance(iter.base(), ptr_); }

		template <typename Iter>
		bool							operator<(const VectorIterator<Iter>& iter) const { return (ptr_ < iter.base()); }
		template <typename Iter>
		bool							operator>(const VectorIterator<Iter>& iter) const { return (ptr_ > iter.base()); }
		template <typename Iter>
		bool							operator<=(const VectorIterator<Iter>& iter) const { return (ptr_ <= iter.base()); }
		template <typename Iter>
		bool							operator>=(const VectorIterator<Iter>& iter) const { return (ptr_ >= iter.base()); }

		_iter							base() const { return ptr_; }

		template <typename U>
		friend	VectorIterator<U>
			operator+(typename VectorIterator<U>::difference_type n, VectorIterator<U>& iter) { return VectorIterator<U>(iter.base() + n); }
		

};

template <typename _iter>
class VectorRevIterator
{
	public:
		typedef	_iter													iterator_type;
		typedef typename std::iterator_traits<_iter>::difference_type	difference_type;
		typedef typename std::iterator_traits<_iter>::reference			reference;
		typedef typename std::iterator_traits<_iter>::pointer			pointer;

	private:
		_iter	current;
	
	public:
		//																	Constructors
		VectorRevIterator() : current() {}

		VectorRevIterator(_iter iter) : current(iter) {}

		template <typename T>
		VectorRevIterator(const VectorRevIterator<T>& iter) : current(iter.base()) {}
		~VectorRevIterator() {}
		
		//																	Operators

		template <typename T>
		VectorRevIterator&				operator=(const VectorRevIterator<T>& iter) { current = iter.base(); return (*this); }

		template <typename Iter>
		bool							operator==(const VectorRevIterator<Iter>& iter) const { return (current == iter.base()); }
		template <typename Iter>
		bool							operator!=(const VectorRevIterator<Iter>& iter) const { return (current != iter.base()); }
		
		reference						operator*() { return (*(current - 1)); }
		reference						operator*()	const { return (*(current - 1)); }
		pointer							operator->() const { return &(operator*()); }
		reference						operator[](difference_type val) const { return *(*this + val); }

		VectorRevIterator&				operator++() { --current; return (*this); }
		VectorRevIterator&				operator--() { ++current; return (*this); }
		VectorRevIterator				operator++(int) { VectorRevIterator	it(*this); --current; return (it); }
		VectorRevIterator				operator--(int) { VectorRevIterator	it(*this); ++current; return (it); }

		VectorRevIterator&				operator+=(difference_type val) { current -= val; return (*this);}
		VectorRevIterator&				operator-=(difference_type val) { current += val; return (*this);}

		VectorRevIterator				operator+(difference_type val) const { return VectorRevIterator(current - val); }
		VectorRevIterator				operator-(difference_type val) const { return VectorRevIterator(current + val); }
		difference_type					operator-(const	VectorRevIterator<_iter>& iter) const { return iter.base() - current; }

		template <typename Iter>
		bool							operator<(const VectorRevIterator<Iter>& iter) const { return (base() > iter.base()); }
		template <typename Iter>
		bool							operator>(const VectorRevIterator<Iter>& iter) const { return (base() < iter.base()); }
		template <typename Iter>
		bool							operator<=(const VectorRevIterator<Iter>& iter) const { return (base() >= iter.base()); }
		template <typename Iter>
		bool							operator>=(const VectorRevIterator<Iter>& iter) const { return (base() <= iter.base()); }

		_iter							base() const { return current; }

		template <typename U>
		friend	VectorRevIterator<U>
			operator+(typename VectorRevIterator<U>::difference_type n, VectorRevIterator<U>& iter) { return VectorRevIterator<U>(iter.base() - n); }
};

}
