/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:37:52 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/27 20:45:25 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <memory>

namespace ft {

template <typename T>
class VectorIterator
{
	private:
		T*	ptr;
	
	public:
		VectorIterator();
		~VectorIterator();
};

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	public:
		typedef T									value_type;
		typedef Alloc								allocator_type;
		typedef	typename Alloc::reference			reference;
		typedef typename Alloc::const_reference		const_reference;
		typedef typename Alloc::pointer				pointer;
		typedef typename Alloc::const_pointer		const_pointer;
		typedef VectorIterator<value_type>			iterator;
		// typedef typename VectorIterator<const T>	const_iterator;
		// typedef typename rev_vector_iterator<T>	reverse_iterator;
		// typedef typename							const_reverse_iterator;
		typedef	ptrdiff_t							difference_type;
		typedef	size_t								size_type;

	private:
		pointer					data_;
		size_type				size_;
		size_type				capacity_;
		allocator_type			alloc_;
	public:
		//																		Constructors
		explicit vector(const allocator_type& alloc = allocator_type()) {};
		// vector (size_type n, const value_type& val = value_type(),
		// const allocator_type& alloc = allocator_type());
		// template <class InputIterator> vector (InputIterator first, InputIterator last,
		// const allocator_type& alloc = allocator_type());
		// vector (const vector& x);
		// ~vector();

		//																		Iterators

		// //Iterators
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
      	// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		// 																		Capacity
		size_type		size() const { return size_; };

		size_type		max_size() const { return alloc_.max_size(); };

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
			T	*new_data;

			new_data = alloc_.allocate(n, 0);
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			alloc_.construct(&new_data[size_], val);
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			capacity_ = n;
			size_ = n;
		}

		size_type		capacity() const { return capacity_; };

		bool			empty() const { return (size_ == 0); };

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
			T*	new_data;

			new_data = alloc_.allocate(n, 0);
			for (size_t i = 0; i < size_; ++i)
				new_data[i] = data_[i];
			alloc_.deallocate(data_, capacity_);
			data_ = new_data;
			capacity_ = n;
		}

		//																		Access
		reference		operator[] (size_type n) { return data_[n]; };

		const_reference	operator[] (size_type n) const { return data_[n]; };

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

		reference		front() { return *data_; };

		const_reference	front() const { return *data_; };

		reference		back() { return data_[size_ - 1]; };

		const_reference	back() const { return data_[size_ - 1]; };

		//																		Modifiers

		// template <class InputIterator> void assign (InputIterator first, InputIterator last); ???
		// void assign (size_type n, const value_type& val);
		void			push_back (const reference val) {
			if (size_ < capacity_){
				data_[size_] = val;
				++size_;
				return ;
			}
			T	*new_data;

			new_data = alloc_.allocate(size_ + 1, 0);
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

		// iterator insert (iterator position, const value_type& val); ???
    	// void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); ???
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
