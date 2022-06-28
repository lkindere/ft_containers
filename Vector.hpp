/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:37:52 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/28 22:48:44 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "VectorIterator.hpp"
#include <memory>

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
		typedef VectorIterator<value_type>				iterator;
		typedef VectorIterator<const value_type>		const_iterator;
		typedef VectorRevIterator<value_type>			reverse_iterator;
		typedef VectorRevIterator<const value_type>		const_reverse_iterator;
		typedef	ptrdiff_t								difference_type;
		typedef	size_t									size_type;

	private:
		pointer					data_;
		size_type				size_;
		size_type				capacity_;
		allocator_type			alloc_;

	public:
		//																		Constructors
		explicit vector (const allocator_type& alloc = allocator_type()) : data_(nullptr), size_(0), capacity_(0)  {}
		// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		// vector (const vector& x);
		// ~vector();

		vector&	operator= (const vector& x) {
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

		const_iterator begin() const { return const_iterator(data_); }

		iterator end() { return iterator(&data_[size_]); }

		const_iterator end() const { return const_iterator(&data_[size_]); }

		reverse_iterator rbegin() { return reverse_iterator(&data_[size_ - 1]); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(&data_[size_ - 1]); }

      	reverse_iterator rend() { return reverse_iterator(&data_[-1]); }

		const_reverse_iterator rend() const { return const_reverse_iterator(&data_[-1]); }


		// 																		Capacity
		size_type		size() const { return size_; }

		size_type		max_size() const { return alloc_.max_size(); }

		void			resize (size_type n, value_type val){
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
			value_type*	new_data = alloc_.allocate(n, 0);
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			alloc_.construct(&new_data[size_], val);
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			capacity_ = n;
			size_ = n;
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
			value_type*	new_data = alloc_.allocate(n, 0);
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


		//Seems to be fighting with the variation below something something enable if???
		
		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last) {
		// 	size_type	n = std::distance(first, last);
		// 	for (;size_ != 0; --size_)
		// 		alloc_.destroy(&data_[size_ - 1]);
		// 	if (n > capacity_){
		// 		alloc_.deallocate(data_, capacity_);
		// 		data_ = alloc_.allocate(n, 0);
		// 	}
		// 	for (;first != last; ++first)
		// 		alloc_.construct(&data_[size_++], *first);
		// }
	
		void assign (size_type n, const value_type& val) {
			for (;size_ != 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
			if (n > capacity_){
				alloc_.deallocate(data_, capacity_);
				data_ = alloc_.allocate(n, 0);
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
			value_type*	new_data = alloc_.allocate(size_ + 1, 0);
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			alloc_.construct(&new_data[size_], val);
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			++capacity_;
			++size_;
		}

		void			pop_back()  {
			alloc_.destroy(&data_[size_ - 1]);
			--size_;
		};

		iterator insert (iterator position, const value_type& val) {
			if (size_ == capacity_){
				size_type	i = 0;
				value_type	*new_data = alloc_.allocate(capacity_ + 1, 0);

				for (iterator it = begin(); it != position; ++it)
					new_data[i++] = *it;
				alloc_.construct(&new_data[i], val);
				iterator ret(&new_data[i]);
				for (; position != end(); ++position)
					new_data[++i] = *position;
				alloc_.deallocate(data_, capacity_);
				data_ = new_data;
				++capacity_;
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
				value_type	*new_data = alloc_.allocate(capacity_ + n, 0);

				for (iterator	it = begin(); it != position; ++it)
					new_data[i++] = *it;
				for (size_type	j = 0; j < n; ++j)
					alloc_.construct(&new_data[i + j], val);
				i += n - 1;
				iterator ret(&new_data[i]);
				for (; position != end(); ++position)
					new_data[++i] = *position;
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

		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);
		
		// iterator erase (iterator position); ???
		// iterator erase (iterator first, iterator last); ???
		// void swap (vector& x);

		void clear() {
			for (;size_ > 0; --size_)
				alloc_.destroy(&data_[size_ - 1]);
		}

		// //Allocator ????

		// //Non member overloads ????
};
}
