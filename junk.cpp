/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/07 15:08:57 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	srand(time(NULL));
	ft::tree<int, ft::pair<int, float> >	tree;

	// tree.insertNode(ft::make_pair(100, 5.5));
	// tree.insertNode(ft::make_pair(183, 52.3));
	// tree.insertNode(ft::make_pair(176, 50.3));
	// tree.insertNode(ft::make_pair(13, 5.5));
	// tree.insertNode(ft::make_pair(119, 52.3));
	// tree.insertNode(ft::make_pair(131, 50.3));
	// tree.insertNode(ft::make_pair(161, 50.3));
	// tree.insertNode(ft::make_pair(175, 52.3));
	// // tree.printTree();
	// // std::cout << "\n\n";
	// tree.insertNode(ft::make_pair(165, 50.3));
	// // std::cout << "Before bugged insertion:\n";
	// tree.printTree();
	// 	std::cout << "\n\n";
	// tree.insertNode(ft::make_pair(48, 50.3));
	// tree.printTree();
	// 	std::cout << "\n\n";


	// tree.printTree();
	// std::cout << "\n\n";

	// tree.rightRotate(tree.root_->left);

	// tree.printTree();
	// std::cout << "\n\n";
	
	// tree.leftRotate(tree.root_->left);

	// tree.printTree();

	std::vector<int>			vec;
	std::vector<int>::iterator	it;
	bool						dup;
	for (int i = 0; i < 10000; ++i){
		int	rng = rand() % 10000;
		dup = false;
		for (it = vec.begin(); it != vec.end(); ++it){
			if (*it == rng)
				dup = true;
		}
		if (!dup){
			vec.push_back(rng);
			std::cout << "Inserting " << rng << std::endl;
			tree.insertNode(ft::make_pair(rng, 5.5));
			tree.printTree();
			std::cout << "\n\n";
		}
	}
	// tree.printTree();
	system("leaks a.out");
	return 0;
}