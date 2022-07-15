/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 12:11:32 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

#include "Map.hpp"

int	main(void)
{
	std::cout << typeid(std::map<int, float>::reverse_iterator::value_type).name() << std::endl;
	std::cout << typeid(std::map<int, float>::reverse_iterator::pointer).name() << std::endl;
	std::cout << typeid(std::map<int, float>::reverse_iterator::reference).name() << std::endl;
	std::cout << typeid(std::map<int, float>::reverse_iterator::difference_type).name() << std::endl;


	std::cout << typeid(ft::map<int, float>::reverse_iterator::value_type).name() << std::endl;
	std::cout << typeid(ft::map<int, float>::reverse_iterator::pointer).name() << std::endl;
	std::cout << typeid(ft::map<int, float>::reverse_iterator::reference).name() << std::endl;
	std::cout << typeid(ft::map<int, float>::reverse_iterator::difference_type).name() << std::endl;
	return 0;
}