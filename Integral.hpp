/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:02:54 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/30 16:32:57 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace	ft {

//																		Remove cv

template <typename T>
struct type_identity { typedef T type; };

template <typename T>
struct remove_const : type_identity<T> {};

template <typename T>
struct remove_const<T const> : type_identity<T> {}; 

template <typename T>
struct remove_volatile : type_identity<T> {};

template <typename T>
struct remove_volatile<T volatile> : type_identity<T> {}; 


//																		Integral

template <typename T, T v>
struct integral_constant { static const T value = v; };

typedef ft::integral_constant<bool, true> true_type;
typedef ft::integral_constant<bool, false> false_type;

template <typename T>
struct is_int : false_type {};

template <> struct is_int<bool> 				: true_type {};
template <> struct is_int<char> 				: true_type {};
template <> struct is_int<signed char> 			: true_type {};
template <> struct is_int<unsigned char> 		: true_type {};
template <> struct is_int<char16_t> 			: true_type {};
template <> struct is_int<char32_t> 			: true_type {};
template <> struct is_int<wchar_t> 				: true_type {};
template <> struct is_int<short> 				: true_type {};
template <> struct is_int<unsigned short> 		: true_type {};
template <> struct is_int<int> 					: true_type {};
template <> struct is_int<unsigned int> 		: true_type {};
template <> struct is_int<long> 				: true_type {};
template <> struct is_int<unsigned long> 		: true_type {};
template <> struct is_int<long long> 			: true_type {};
template <> struct is_int<unsigned long long> 	: true_type {};

template <typename T>
struct is_integral
	: ft::is_int<typename ft::remove_const<typename ft::remove_volatile<T>::type>::type> {};


//																		Enable if

template <bool B, typename T = void>
struct enable_if {};
 
template <typename T>
struct enable_if<true, T> { typedef T type; };


}
