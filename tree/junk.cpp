/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/12 12:10:06 by lkindere         ###   ########.fr       */
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

enum	e_stuff {whatever, stuff};

int	main(void)
{
	srand(time(NULL));
	ft::set<int>					whatever;

	whatever.insert(3);
	// whatever.insert(6);
	// whatever.insert(9);
	// whatever.insert(12);
	// whatever.insert(15);
	// whatever.insert(18);
	// whatever.insert(21);
	// whatever.insert(24);
	// whatever.insert(27);
	// whatever.insert(30);

	ft::set<int>::iterator			it = whatever.begin();
	ft::set<int>::iterator			end = whatever.end();
	ft::set<int>::reverse_iterator	rit = whatever.rbegin();
	ft::set<int>::reverse_iterator	rend = whatever.rend();

	// for (; it != end; ++it)
	// 	std::cout << *it << std::endl;

	// std::cout << (rit == rend);

	for (; rit != rend; ++rit)
		std::cout << *rit << std::endl;


	// std::cout << (whatever.find(8) == whatever.end()) << std::endl;

	// whatever.base_.printTree();

	// ft::set<int>			clone(whatever);

	// std::cout << *clone.lower_bound(10) << std::endl;
	// std::cout << *clone.upper_bound(10) << std::endl;

	// std::cout << whatever.max_size() << std::endl;
	// std::cout << stdset.max_size() << std::endl;

	// whatever.base_.printTree();

	// // std::cout << *whatever.lower_bound(16) << std::endl;

	// std::cout << *whatever.equal_range(16).first <<std::endl << *whatever.equal_range(16).second << std::endl;



	return 0;
}