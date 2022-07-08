/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/08 23:04:30 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	srand(time(NULL));
	ft::tree<int, ft::pair<int, float> >	tree;

	//    CASE / \ CASE

	// {	//Seems functional
	// 	std::cout << "S is right of P, red is right \\ \n";
	// 	tree.root_ = tree.allocNode(ft::make_pair(30, 5.5));
	// 	tree.root_->color = black;

	// 	tree.root_->left = tree.allocNode(ft::make_pair(20, 5.5), tree.root_);
	// 	tree.root_->left->color = black;

	// 	tree.root_->right = tree.allocNode(ft::make_pair(40, 5.5), tree.root_);
	// 	tree.root_->right->color = black;

	// 	tree.root_->right->left = tree.allocNode(ft::make_pair(35, 5.5), tree.root_->right);
	// 	tree.root_->right->left->color = red;

	// 	tree.root_->right->right = tree.allocNode(ft::make_pair(50, 5.5), tree.root_->right);
	// 	tree.root_->right->right->color = red;
	
	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.remove(tree.root_->left->right->left);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
	// }
	// {	//Seems functional
	// 	std::cout << "S is left of P, red is right / \n";
	// 	tree.root_ = tree.allocNode(ft::make_pair(30, 5.5));
	// 	tree.root_->color = black;

	// 	tree.root_->right = tree.allocNode(ft::make_pair(40, 5.5), tree.root_);
	// 	tree.root_->right->color = black;

	// 	tree.root_->left = tree.allocNode(ft::make_pair(15, 5.5), tree.root_);
	// 	tree.root_->left->color = black;
		
	// 	tree.root_->left->left = tree.allocNode(ft::make_pair(10, 5.5), tree.root_->left);
	// 	tree.root_->left->left->color = red;

	// 	tree.root_->left->right = tree.allocNode(ft::make_pair(20, 5.5), tree.root_->left);
	// 	tree.root_->left->right->color = red;

	
	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.remove(tree.root_->left->right->right);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
	// }

	// 	//	CASE < > CASE


	// {	//Seems functional
	// 	std::cout << "S is right of P, red is left > \n";
	// 	tree.root_ = tree.allocNode(ft::make_pair(30, 5.5));
	// 	tree.root_->color = black;

	// 	tree.root_->left = tree.allocNode(ft::make_pair(20, 5.5), tree.root_);
	// 	tree.root_->left->color = black;

	// 	tree.root_->right = tree.allocNode(ft::make_pair(40, 5.5), tree.root_);
	// 	tree.root_->right->color = black;

	// 	tree.root_->right->left = tree.allocNode(ft::make_pair(35, 5.5), tree.root_->right);
	// 	tree.root_->right->left->color = red;

	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.remove(tree.root_->left->right->left);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
	// }
	// {	//Seems functional
	// 	std::cout << "S is left of P, red is left < \n";
	// 	tree.root_ = tree.allocNode(ft::make_pair(30, 5.5));
	// 	tree.root_->color = black;

	// 	tree.root_->left = tree.allocNode(ft::make_pair(20, 5.5), tree.root_);
	// 	tree.root_->left->color = black;

	// 	tree.root_->right = tree.allocNode(ft::make_pair(40, 5.5), tree.root_);
	// 	tree.root_->right->color = black;

	// 	tree.root_->left->right = tree.allocNode(ft::make_pair(25, 5.5), tree.root_->left);
	// 	tree.root_->left->right->color = red;

	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.remove(tree.root_->left->right->right);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
	// }

	// {	//Seems functional
	// 	std::cout << "Both black recolor\n";
	// 	tree.root_ = tree.allocNode(ft::make_pair(20, 5.5));
	// 	tree.root_->color = black;

	// 	tree.root_->left = tree.allocNode(ft::make_pair(10, 5.5), tree.root_);
	// 	tree.root_->left->color = black;

	// 	tree.root_->right = tree.allocNode(ft::make_pair(30, 5.5), tree.root_);
	// 	tree.root_->right->color = black;

	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.remove(tree.root_->left->right->left);
	// 	tree.printTree();
	// }

	// {	//Seems functional
	// 	std::cout << "S is right of P, red is left\n";
	// 	tree.root_ = tree.allocNode(ft::make_pair(20, 5.5));
	// 	tree.root_->color = black;

	// 	tree.root_->left = tree.allocNode(ft::make_pair(10, 5.5), tree.root_);
	// 	tree.root_->left->color = black;

	// 	tree.root_->right = tree.allocNode(ft::make_pair(30, 5.5), tree.root_);
	// 	tree.root_->right->color = red;

	// 	tree.root_->right->left = tree.allocNode(ft::make_pair(25, 5.5), tree.root_->right);
	// 	tree.root_->right->left->color = black;

	// 	tree.root_->right->right = tree.allocNode(ft::make_pair(35, 5.5), tree.root_->right);
	// 	tree.root_->right->right->color = black;

	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.remove(tree.root_->left->right->left);
	// 	tree.printTree();
	// }

	// tree.insertNode(ft::make_pair(18, 50.3));
	// tree.insertNode(ft::make_pair(9, 50.3));
	// tree.insertNode(ft::make_pair(12, 50.3));
	// tree.insertNode(ft::make_pair(5, 50.3));
	// tree.insertNode(ft::make_pair(2, 50.3));
	// tree.insertNode(ft::make_pair(0, 50.3));
	// tree.insertNode(ft::make_pair(3, 50.3));
	// tree.insertNode(ft::make_pair(15, 50.3));
	// tree.insertNode(ft::make_pair(14, 50.3));
	// tree.insertNode(ft::make_pair(10, 50.3));

	// tree.remove(tree.root_->left->right->right);
	// tree.remove(tree.root_->left->right->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// tree.remove(tree.root_->left->right->right);
	// tree.printTree();
	// std::cout << "\n\n";

	std::vector<int>			vec;
	std::vector<int>::iterator	it;
	bool						dup;
	for (int i = 0; i < 25; ++i){
		int	rng = rand() % 20;
		dup = false;
		for (it = vec.begin(); it != vec.end(); ++it){
			if (*it == rng)
				dup = true;
		}
		if (!dup){
			vec.push_back(rng);
			std::cout << "Inserting " << rng << std::endl;
			tree.insertNode(ft::make_pair(rng, 5.5));
		}
	}
	tree.printTree();
	std::cout << "\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";

	tree.remove(tree.root_->left->right);
	tree.printTree();
	std::cout << "\n\n\n";
	system("leaks a.out");
	return 0;
}