/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 02:40:25 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/12 23:52:26 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

template <class T1, class T2>
struct pair
{
	public:
		T1	first;
		T2	second;

	public:
		pair() : first(), second() {}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

		pair( const T1& x, const T2& y ) : first(x), second(y) {}

		pair&	operator= (const pair& pr) { first = pr.first; second = pr.second; return *this; }
};

template <class T1, class T2>
pair<T1,T2>		make_pair(T1 x, T2 y) { return pair<T1, T2>(x, y); }

template <class T1, class T2>
bool			operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second); }

template <class T1, class T2>
bool			operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }

template <class T1, class T2>
bool			operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

template <class T1, class T2>
bool			operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }

template <class T1, class T2>
bool			operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }

template <class T1, class T2>
bool			operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

}
