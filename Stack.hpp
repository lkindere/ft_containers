/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:30:33 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/04 00:55:17 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"

namespace ft {


template <typename T, class Ctn = ft::vector<T> >
class stack
{
	public:
		typedef T			value_type;
		typedef Ctn			container_type;
		typedef size_t		size_type;
		
	private:
		container_type		ctn_;
	
	public:
		//																	Constructors

		explicit stack (const container_type& ctnr = container_type()) : ctn_(ctnr) {}
		~stack() {}
		
		
		//																	Member functions

		bool				empty() const { return ctn_.empty(); }
		size_type			size() const { return ctn_.size(); }
		value_type&			top() { return ctn_.back(); }
		const value_type&	top() const { return ctn_.back(); }
		void				push (const value_type& val) { ctn_.push_back(val); }
		void				pop() { ctn_.pop_back(); }

		//																	Relational operators

		friend bool operator== (const stack<T,Ctn>& lhs, const stack<T,Ctn>& rhs) { return lhs.ctn_ == rhs.ctn_; }
		friend bool operator!= (const stack<T,Ctn>& lhs, const stack<T,Ctn>& rhs) { return lhs.ctn_ != rhs.ctn_; }
		friend bool operator<  (const stack<T,Ctn>& lhs, const stack<T,Ctn>& rhs) { return lhs.ctn_ < rhs.ctn_; }
		friend bool operator<= (const stack<T,Ctn>& lhs, const stack<T,Ctn>& rhs) { return lhs.ctn_ <= rhs.ctn_; }
		friend bool operator>  (const stack<T,Ctn>& lhs, const stack<T,Ctn>& rhs) { return lhs.ctn_ > rhs.ctn_; }
		friend bool operator>= (const stack<T,Ctn>& lhs, const stack<T,Ctn>& rhs) { return lhs.ctn_ >= rhs.ctn_; }
};

}
