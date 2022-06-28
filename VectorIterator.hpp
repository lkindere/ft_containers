/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:52:58 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/28 18:56:36 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace	ft {
template <typename T>
class VectorIterator
{
	public:
		typedef	T									value_type;
		typedef	T*									pointer;
		typedef T&									reference;
		typedef	ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		
	private:
		pointer		ptr_;
	
	public:
		//																	Constructors
		VectorIterator(pointer ptr = nullptr) { ptr_ = ptr; }
		VectorIterator(const VectorIterator<value_type>& iter) { ptr_ = iter.ptr_; }
		~VectorIterator() {}
		
		//																	Operators
		VectorIterator<value_type>&		operator=(pointer ptr) { ptr_ = ptr; return (*this); }

		bool							operator==(const VectorIterator<value_type>& iter) const {
			return (ptr_ == iter.ptr_);
		}

		bool							operator!=(const VectorIterator<value_type>& iter) const {
			return (ptr_ != iter.ptr_);
		}
		
		value_type&						operator*()	{ return (*ptr_); }
		pointer							operator->() { return ptr_; }

		VectorIterator<value_type>&		operator++() { ++ptr_; return (*this); }
		VectorIterator<value_type>&		operator--() { --ptr_; return (*this); }

		VectorIterator<value_type>		operator++(int) {
			VectorIterator<value_type>	it = (*this);
			++ptr_; return (it);	
		}

		VectorIterator<value_type>		operator--(int) {
			VectorIterator<value_type>	it = (*this);
			--ptr_; return (it);	
		}

		VectorIterator<value_type>		operator+(difference_type val) { return VectorIterator<value_type>(ptr_ + val); }
		VectorIterator<value_type>		operator-(difference_type val) { return VectorIterator<value_type>(ptr_ - val); }
		difference_type					operator-(const	VectorIterator<value_type>& iter) { return std::distance(iter.ptr_, ptr_); }

		VectorIterator<value_type>&		operator+=(difference_type val) { ptr_ += val; return (*this);}
		VectorIterator<value_type>&		operator-=(difference_type val) { ptr_ -= val; return (*this);}

		bool							operator<(VectorIterator<value_type>& iter) { return (ptr_ < iter.ptr_()); }
		bool							operator>(VectorIterator<value_type>& iter) { return (ptr_ > iter.ptr_()); }
		bool							operator<=(VectorIterator<value_type>& iter) { return (ptr_ <= iter.ptr_()); }
		bool							operator>=(VectorIterator<value_type>& iter) { return (ptr_ >= iter.ptr_()); }

		value_type						operator[](difference_type val) { return (ptr_[val]); }
};

template <typename T>
class VectorRevIterator
{
	public:
		typedef	T									value_type;
		typedef	T*									pointer;
		typedef T&									reference;
		typedef	ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		
	private:
		pointer		ptr_;
	
	public:
		//																	Constructors
		VectorRevIterator(pointer ptr = nullptr) { ptr_ = ptr; }
		VectorRevIterator(const VectorRevIterator<value_type>& iter) { ptr_ = iter.ptr_; }
		~VectorRevIterator() {}
		
		//																	Operators
		VectorRevIterator<value_type>&	operator=(pointer ptr) { ptr_ = ptr; return (*this); }

		bool							operator==(const VectorRevIterator<value_type>& iter) const {
			return (ptr_ == iter.ptr_);
		}

		bool							operator!=(const VectorRevIterator<value_type>& iter) const {
			return (ptr_ != iter.ptr_);
		}
		
		value_type						operator*()	{ return (*ptr_); }
		pointer							operator->() { return ptr_; }

		VectorRevIterator<value_type>&	operator++() { --ptr_; return (*this); }
		VectorRevIterator<value_type>&	operator--() { ++ptr_; return (*this); }

		VectorRevIterator<value_type>	operator++(int) {
			VectorRevIterator<value_type> it = (*this);
			--ptr_; return (it);	
		}

		VectorRevIterator<value_type>		operator--(int) {
			VectorRevIterator<value_type> it = (*this);
			++ptr_; return (it);	
		}

		VectorRevIterator<value_type>	operator+(difference_type val) { return VectorRevIterator<value_type>(ptr_ - val); }
		VectorRevIterator<value_type>	operator-(difference_type val) { return VectorRevIterator<value_type>(ptr_ + val); }
		VectorRevIterator<value_type>&	operator+=(difference_type val) { ptr_ -= val; return (*this);}
		VectorRevIterator<value_type>&	operator-=(difference_type val) { ptr_ += val; return (*this);}

		bool							operator<(VectorRevIterator<value_type>& iter) { return (ptr_ > iter.ptr_()); }
		bool							operator>(VectorRevIterator<value_type>& iter) { return (ptr_ < iter.ptr_()); }
		bool							operator<=(VectorRevIterator<value_type>& iter) { return (ptr_ >= iter.ptr_()); }
		bool							operator>=(VectorRevIterator<value_type>& iter) { return (ptr_ <= iter.ptr_()); }

		value_type						operator[](difference_type val) { return (ptr_[-val]); }
};
}
