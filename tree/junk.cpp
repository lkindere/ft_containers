/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/12 22:58:09 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <vector>
// #include <map>
// #include <set>

// #include "Set.hpp"

#include <unistd.h>

#include "RBTree.hpp"

#include "Set.hpp"

#include "Map.hpp"

enum	e_stuff {whatever, stuff};

int	main(void)
{
	srand(time(NULL));
	ft::map<int, float>		map;
	ft::map<int, float>		map2;

	std::cout << (map == map2);

	// std::cout << map.empty() << " : " << map.size() << std::endl;
	// map.insert(ft::make_pair(5, 5.5));
	// map.insert(ft::make_pair(8, 5.5));

	// for (ft::map<int, float>::iterator it = map.begin(); it != map.end(); ++it)
	// 	std::cout << it->first << std::endl;

	return 0;
}