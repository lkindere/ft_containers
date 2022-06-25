/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:59:28 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/25 19:27:45 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <exception>
#include <iostream>

//																					CONSTRUCTORS

template <typename T>
ft::vector<T>::vector() {std::cout << "Constructed or smth\n";};

// vector (size_type n, const value_type& val = value_type(),
// const allocator_type& alloc = allocator_type());
// template <class InputIterator> vector (InputIterator first, InputIterator last,
// const allocator_type& alloc = allocator_type());
// vector (const vector& x);
template <typename T>
ft::vector<T>::~vector() {std::cout << "Deconstructed or smth\n";};

//																					ITERATORS

// iterator begin();
// const_iterator begin() const;
// iterator end();
// const_iterator end() const;
// reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
// reverse_iterator rend();
// const_reverse_iterator rend() const;

//																					CAPACITY

template <typename T>
size_t ft::vector<T>::size() const {return size_;};

template <typename T>
size_t ft::vector<T>::max_size() const {return alloc_.max_size();};

template <typename T>
void ft::vector<T>::resize (size_t n, T val) {
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

template <typename T>
size_t ft::vector<T>::capacity() const {return capacity_;};

template <typename T>
bool ft::vector<T>::empty() const {return (size_ == 0);};

template <typename T>
void ft::vector<T>::reserve (size_t n) {
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

//																					ACCESS

//Not bounds protected
template <typename T>
T& ft::vector<T>::operator[] (size_t n) {return data_[n];};

//Not bounds protected
template <typename T>
const T& ft::vector<T>::operator[] (size_t n) const {return data_[n];};

template <typename T>
T& ft::vector<T>::at (size_t n){
	if (n >= size_ || n < 0)
		throw(std::out_of_range("ft_vector"));
	return (data_[n]);
}

template <typename T>
const T& ft::vector<T>::at (size_t n) const{
	if (n >= size_ || n < 0)
		throw(std::out_of_range("ft_vector"));
	return (data_[n]);
}

template <typename T>
T& ft::vector<T>::front() {return *data_;};

template <typename T>
const T& ft::vector<T>::front() const {return *data_;};

//Empty containers cause undefined behaviour
template <typename T>
T& ft::vector<T>::back() {return data_[size_ - 1];};

//Empty containers cause undefined behaviour
template <typename T>
const T& ft::vector<T>::back() const {return data_[size_ - 1];};

//																					MODIFIERS

// template <class InputIterator> void assign (InputIterator first, InputIterator last); ???
// void assign (size_type n, const value_type& val);

template <typename T>
void ft::vector<T>::push_back (const T& val){
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

//Empty containers cause undefined behaviour
template <typename T>
void ft::vector<T>::pop_back() {
	alloc_.destroy(&data_[size_ - 1]);
	--size_;
};

// iterator insert (iterator position, const value_type& val); ???
// void insert (iterator position, size_type n, const value_type& val);
// template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); ???
// iterator erase (iterator position); ???
// iterator erase (iterator first, iterator last); ???
// void swap (vector& x);

template <typename T>
void ft::vector<T>::clear(){
	for (;size_ > 0; --size_)
		alloc_.destroy(&data_[size_ - 1]);
}

// //Allocator ????
// //Non member overloads ????