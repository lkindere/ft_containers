/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/05 20:39:28 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include <iostream>

int	main(void)
{
	ft::tree<int, ft::pair<int, float> >	tree;

	tree.insertNode(ft::make_pair(50, 5.5));
	tree.insertNode(ft::make_pair(30, 52.3));
	tree.insertNode(ft::make_pair(80, 50.3));

	tree.insertNode(ft::make_pair(20, 5.5));
	tree.insertNode(ft::make_pair(40, 52.3));
	tree.insertNode(ft::make_pair(60, 50.3));

	tree.insertNode(ft::make_pair(90, 52.3));
	tree.insertNode(ft::make_pair(1, 50.3));
	tree.insertNode(ft::make_pair(25, 50.3));
	tree.insertNode(ft::make_pair(35, 50.3));
	tree.insertNode(ft::make_pair(46, 50.3));
	tree.insertNode(ft::make_pair(50, 50.3));
	tree.insertNode(ft::make_pair(35, 50.3));
	tree.insertNode(ft::make_pair(46, 50.3));

	tree.printTree();

	return 0;
}