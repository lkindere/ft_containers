/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:37:52 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/25 19:29:09 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <memory>

namespace ft {
template <typename T>
class vector
{
	private:
		T*					data_;
		size_t				size_;
		size_t				capacity_;
		std::allocator<T>	alloc_;
	public:
		//Constructors
		vector();
		// vector (size_type n, const value_type& val = value_type(),
		// const allocator_type& alloc = allocator_type());
		// template <class InputIterator> vector (InputIterator first, InputIterator last,
		// const allocator_type& alloc = allocator_type());
		// vector (const vector& x);
		~vector();

		// //Iterators
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
      	// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		// // Capacity
		size_t size() const;
		size_t max_size() const;
		void resize (size_t n, T val);
		size_t capacity() const;
		bool empty() const;
		void reserve (size_t n);

		// // Access
		T& operator[] (size_t n);
		const T& operator[] (size_t n) const;
		T& at (size_t n);
		const T& at (size_t n) const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

		// //Modifiers
		// template <class InputIterator> void assign (InputIterator first, InputIterator last); ???
		// void assign (size_type n, const value_type& val);
		void push_back (const T& val);
		void pop_back();
		// iterator insert (iterator position, const value_type& val); ???
    	// void insert (iterator position, size_type n, const value_type& val);
		// template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); ???
		// iterator erase (iterator position); ???
		// iterator erase (iterator first, iterator last); ???
		// void swap (vector& x);
		void clear();

		// //Allocator ????

		// //Non member overloads ????
};
}

#include "ft_vector.tpp"