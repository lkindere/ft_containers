/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:37:52 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 15:38:39 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

#include "utils/Integral.hpp"
#include "utils/VectorIterator.hpp"

namespace ft {
template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	public:
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef	typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef	ptrdiff_t								difference_type;
		typedef	size_t									size_type;
		typedef VectorIterator<pointer>					iterator;
		typedef VectorIterator<const_pointer>			const_iterator;
		typedef VectorRevIterator<iterator>				reverse_iterator;
		typedef VectorRevIterator<const_iterator>		const_reverse_iterator;

	private:
		pointer					data_;
		size_type				size_;
		size_type				capacity_;
		allocator_type			alloc_;

	public:
		//																		Constructors

		explicit vector
			(const allocator_type& alloc = allocator_type())
			: data_(nullptr), size_(0), capacity_(0), alloc_(alloc)  {}
		
		explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
			: data_(nullptr), size_(0), capacity_(0), alloc_(alloc) { assign(n, val); }

		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type())
			:	data_(nullptr), size_(0), capacity_(0), alloc_(alloc) { assign(first, last); }
			
		vector (const vector& x) :	data_(nullptr), size_(0), capacity_(0) { *this = x; };
	
		~vector() {
			for (;size_ > 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
			alloc_.deallocate(data_, capacity_);
		}

		vector&	operator= (const vector& x) {
			if (x == *this)
				return *this;
			for (;size_ > 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
			if (capacity_ < x.size_){
				alloc_.deallocate(data_, capacity_);
				data_ = alloc_.allocate(x.size_);
				capacity_ = x.size_;
			}
			for (;size_ < x.size_; ++size_)
				alloc_.construct(&data_[size_], x.data_[size_]);
			return (*this);
		}


		//																		Iterators

		iterator begin() { return iterator(data_); }
		iterator end() { return iterator(&data_[size_]); }

		const_iterator begin() const { return iterator(data_); }
		const_iterator end() const { return iterator(&data_[size_]); }

		reverse_iterator rbegin() { return end(); }
      	reverse_iterator rend() { return begin(); }

		const_reverse_iterator rbegin() const { return end(); }
		const_reverse_iterator rend() const { return begin(); }

		// 																		Capacity

		size_type		size() const { return size_; }

		size_type		max_size() const { return alloc_.max_size(); }

		void			resize (size_type n, value_type val = value_type()){
			if (n == size_)
				return ;
			if (n < size_){
				for (;size_ > n; --size_)
					alloc_.destroy(&data_[size_ - 1]);
				return ;
			}
			if (n < capacity_){
				for (;size_ < n; ++size_)
					alloc_.construct(&data_[size_], val);
				return ;
			}
			size_type	new_cap = 1;
			if (capacity_ > 0)
				new_cap = capacity_;
			while (new_cap < n)
				new_cap *= 2;
			value_type*	new_data = alloc_.allocate(new_cap);
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			for (;size_ != n; ++size_)
				alloc_.construct(&new_data[size_], val);
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			capacity_ = new_cap;
		}

		size_type		capacity() const { return capacity_; }

		bool			empty() const { return (size_ == 0); }

		void			reserve (size_type n) {
			if (n <= capacity_) return;
			if (capacity_ == 0){
				data_ = alloc_.allocate(n);
				capacity_ = n;
				return ;
			}
			if (size_ == 0){
				alloc_.deallocate(data_, capacity_);
				data_ = alloc_.allocate(n);
				capacity_ = n;
				return ;
			}
			value_type*	new_data = alloc_.allocate(n);
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			capacity_ = n;
		}


		//																		Access

		reference		operator[] (size_type n) { return data_[n]; }

		const_reference	operator[] (size_type n) const { return data_[n]; }

		reference		at (size_type n) {
			if (n >= size_ || n < 0)
				throw(std::out_of_range("ft_vector"));
			return (data_[n]);
		}

		const_reference	at (size_type n) const {
			if (n >= size_ || n < 0)
				throw(std::out_of_range("ft_vector"));
			return (data_[n]);
		}

		reference		front() { return *data_; }

		const_reference	front() const { return *data_; }

		reference		back() { return data_[size_ - 1]; }

		const_reference	back() const { return data_[size_ - 1]; }


		//																		Modifiers
		
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
						assign (InputIterator first, InputIterator last) {
			if (sizeof(*first) != sizeof(*data_))
				throw(std::invalid_argument("Invalid datatype"));
			size_type	n = std::distance(first, last);
			for (;size_ != 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
			if (n > capacity_){
				alloc_.deallocate(data_, capacity_);
				data_ = alloc_.allocate(n);
				capacity_ = n;
			}
			for (;first != last; ++first)
				alloc_.construct(&data_[size_++], *first);
		}
	
		void			assign (size_type n, const value_type& val) {
			for (;size_ != 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
			if (n > capacity_){
				alloc_.deallocate(data_, capacity_);
				data_ = alloc_.allocate(n);
				capacity_ = n;
			}
			for (;size_ < n; ++size_)
				alloc_.construct(&data_[size_], val);
		}

		void			push_back (const value_type& val) {
			if (size_ < capacity_){
				data_[size_] = val;
				++size_;
				return ;
			}
			value_type*		new_data;
			if (capacity_ == 0){
				new_data = alloc_.allocate(1);
				capacity_ = 1;
			}
			else{
				new_data = alloc_.allocate(capacity_ * 2);
				capacity_ *= 2;
			}
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			alloc_.construct(&new_data[size_], val);
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			++size_;
		}

		void			pop_back()  {
			alloc_.destroy(&data_[size_ - 1]);
			--size_;
		};

		iterator insert (iterator position, const value_type& val) {
			if (size_ == capacity_){
				size_type	i = 0;
				value_type	*new_data = alloc_.allocate(capacity_ * 2);
				for (iterator it = begin(); it != position; ++it)
					new_data[i++] = *it;
				alloc_.construct(&new_data[i], val);
				iterator ret(&new_data[i]);
				for (; position != end(); ++position)
					new_data[++i] = *position;
				alloc_.deallocate(data_, capacity_);
				data_ = new_data;
				capacity_ *= 2;
				++size_;
				return ret;
			}
			for (iterator	it(end()); it != position; --it)
				*it = *(it - 1);
			size_++;
			alloc_.construct(&(*position), val);
			return position;
		}
	
    	void insert (iterator position, size_type n, const value_type& val){
			if (size_ + n > capacity_){
				size_type	i = 0;
				value_type	*new_data = alloc_.allocate(size_ + n);
				for (iterator	it = begin(); it != position; ++it)
					new_data[i++] = *it;
				for (size_type	j = 0; j < n; ++j)
					alloc_.construct(&new_data[i + j], val);
				i += n;
				for (; position != end(); ++position)
					new_data[i++] = *position;
				alloc_.deallocate(data_, capacity_);
				data_ = new_data;
				capacity_ = size_ + n;
				size_ += n;
				return ;
			}
			for (iterator	it(end() - 1 + n); it != position; --it)
				*it = *(it - n);
			size_+= n;
			for (;n > 0; --n)
				alloc_.construct(&(*position++), val);
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
			insert (iterator position, InputIterator first, InputIterator last){
			if (sizeof(*first) != sizeof(*data_))
				throw(std::invalid_argument("Invalid datatype"));
			size_type	n = std::distance(first, last);
			if (size_ + n > capacity_){
				size_type	new_cap = 1;
				if (capacity_ > 0)
					new_cap = capacity_;
				while (new_cap < size_ + n)
					new_cap *= 2;
				value_type	*new_data = alloc_.allocate(new_cap);
				size_type	i = 0;

				for (iterator	it = begin(); it != position; ++it)
					new_data[i++] = *it;
				for (;first != last; ++first)
					alloc_.construct(&new_data[i++], *first);
				for (;position != end(); ++position)
					new_data[i++] = *position;
				alloc_.deallocate(data_, capacity_);
				data_ = new_data;
				capacity_ = new_cap;
				size_ += n;
				return ;
			}
			for (iterator	it(end() - 1 + n); it != position; --it)
				*it = *(it - n);
			size_+= n;
			for (;first != last; ++first)
				alloc_.construct(&(*position++), *first);
		}
		
		iterator	erase (iterator position){
			alloc_.destroy(&(*position));
			for (iterator it = position; it != end() - 1; ++it)
				*it = *(it + 1);
			--size_;
			return position;
		}

		iterator	erase (iterator first, iterator last){
			size_type	n = std::distance(first, last);

			for (iterator it = first; it != last; ++it)
				alloc_.destroy(&(*it));
			for (iterator it = last; it != end(); ++it)
				*(it - n) = *it;
			size_ -= n;
			return first;	
		}

		void		swap (vector& x){
			value_type*	temp_data = data_;
			size_type	temp_size = size_;
			size_type	temp_capacity = capacity_;

			data_ = x.data_;
			size_ = x.size_;
			capacity_ = x.capacity_;

			x.data_ = temp_data;
			x.size_ = temp_size;
			x.capacity_ = temp_capacity;
		}

		void		clear() {
			for (;size_ > 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
		}
		

		//																		Allocator

		allocator_type	get_allocator() const { return alloc_; }


		//																		Non member overloads

		friend	bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
			if (lhs.size_ != rhs.size_)
			 	return false;
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		friend bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
			if (lhs.size_ != rhs.size_)
			 	return true;
			return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		friend bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		friend bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
			return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}

		friend bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}

		friend bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
			return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

};
}

namespace ft {

	template <typename T>
	void	swap (ft::vector<T>& x, ft::vector<T> &y) { x.swap(y); }
}

// namespace std {

// 	template <typename T>
// 	void	swap (ft::vector<T>& x, ft::vector<T> &y) { x.swap(y); }
// }
