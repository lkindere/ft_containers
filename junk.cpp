/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/06 21:20:14 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include <iostream>

int	main(void)
{
	srand(time(NULL));
	ft::tree<int, ft::pair<int, float> >	tree;

	tree.insertNode(ft::make_pair(5, 5.5));
	tree.insertNode(ft::make_pair(11, 52.3));
	tree.insertNode(ft::make_pair(29, 50.3));
	tree.insertNode(ft::make_pair(56, 5.5));
	tree.insertNode(ft::make_pair(99, 52.3));
	tree.insertNode(ft::make_pair(18, 50.3));
	tree.insertNode(ft::make_pair(1, 50.3));
	tree.insertNode(ft::make_pair(38, 52.3));
	tree.printTree();
	std::cout << "\n\n";
	tree.insertNode(ft::make_pair(69, 50.3));
	std::cout << "Before bugged insertion:\n";
	tree.printTree();
		std::cout << "\n\n";
	tree.insertNode(ft::make_pair(48, 50.3));
	tree.printTree();
		std::cout << "\n\n";


	// tree.printTree();
	// std::cout << "\n\n";

	// tree.rightRotate(tree.root_->left);

	// tree.printTree();
	// std::cout << "\n\n";
	
	// tree.leftRotate(tree.root_->left);

	// tree.printTree();

	// for (int i = 0; i < 7; ++i){
	// 	int	rng = rand() % 100;
	// 	std::cout << "Inserting " << rng << std::endl;
	// 	tree.insertNode(ft::make_pair(rng, 5.5));
	// 	tree.printTree();
	// }
	// system("leaks a.out");
	return 0;
}