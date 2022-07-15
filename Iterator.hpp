/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:48:39 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 12:17:19 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

//																		Traits

template<class T>
struct iterator_traits
{
    typedef typename T::difference_type		difference_type;
    typedef typename T::value_type			value_type;
    typedef typename T::pointer				pointer;
    typedef typename T::reference			reference;
    typedef typename T::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef ptrdiff_t							difference_type;
    typedef T									value_type;
    typedef T*									pointer;
    typedef T&									reference;
    typedef std::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
    typedef ptrdiff_t							difference_type;
    typedef const T								value_type;
    typedef const T*							pointer;
    typedef const T&							reference;
    typedef std::random_access_iterator_tag		iterator_category;
};

//																		Base
template <typename T>
class _iterator
{
	public:
   		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<T>::value_type 		value_type;
		typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T>::reference			reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
	
	protected:
		pointer		ptr_;
};

}
