/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/10 19:49:03 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "Set.hpp"

int	main(void)
{
	srand(time(NULL));
	
	ft::set<int>			set;
	std::set<int>			std;


	// ft::set<int>::value_compare comp = set.value_comp();

	// std::cout << comp(10, 10);

	set.insert(5);
	set.insert(10);
	set.insert(15);
	set.insert(20);
	set.insert(30);
	set.insert(35);
		set.insert(50);
	set.insert(55);
	set.insert(60);
	set.insert(65);
		set.insert(70);
	set.insert(75);

	std::cout << (set.find(56) == set.end()) << std::endl;

	// ft::set<int>::iterator	it = set.begin();

	// std::cout << "Begin: " << *it << std::endl;

	// for (; it != set.end(); ++it){
	// 	std::cout << *it << std::endl;
	// 	// std::cout << "Begin is: " << *set.begin() << std::endl;
	// 	set.erase(set.begin());
	// }

	// std::cout << "\n\n";

	// for (ft::set<int>::iterator it = set.begin(); it != set.end(); ++it){
	// 	std::cout << *it << std::endl;
	// }

		// for (ft::set<int>::iterator it = set.begin(); it != set.end(); ++it){
		// 	std::cout << *it << std::endl;
		// // set.erase(it);
	// }

	// set.clear();
	// ite = set.end();

	// std::cout << set.size();

	// 		for (ft::set<int>::iterator it = set.begin(); it != ite; ++it)
	// 	std::cout << *it << std::endl;

	// tree.insertNode(5);
	// tree.insertNode(10);
	// tree.insertNode(15);

	// ft::TreeIterator<node<int> >	it(tree.root_);
	// ft::TreeIterator<node<int> >	it2(tree.root_);

	// std::cout << typeid(node<int>::iterator_category).name();
	

	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;
	// std::cout << *it++ << std::endl;


	// std::cout << "\n\n";
	// std::cout << (it == it2) << std::endl;
	// std::cout << "\n\n";

	// std::cout << *it-- << std::endl;
	// std::cout << *it-- << std::endl;
	// std::cout << *it-- << std::endl;
	// std::cout << *it-- << std::endl;


	// std::set<int>	set;

	// set.insert(5);
	// set.insert(10);
	// set.insert(15);

	// std::set<int>::iterator	sit(set.begin());

	// std::cout << *sit << std::endl;
	// ++sit;
	// 	std::cout << *sit << std::endl;
	// 	++sit;
	// 		std::cout << *sit << std::endl;
	// 	++sit;
	// 		std::cout << *sit << std::endl;

	// std::cout << tree.find(5) << std::endl;

	// ft::pair<int, float>	stuff1 = ft::make_pair(3, 6.5);
	// ft::pair<int, float>	stuff2 = ft::make_pair(1, 6.5);
	// ft::node<int>		wat;


	// std::less<

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

	// 	tree.remove(tree.root_->left);
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

	// 	tree.remove(tree.root_->right);
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

	// 	tree.remove(tree.root_->left);
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

	// 	tree.remove(tree.root_->right);
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

	// 	tree.remove(tree.root_->left);
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

	// 	tree.remove(tree.root_->left);
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

	// tree.remove(tree.root_->right);
	// tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// std::set<int>				set;
	// std::vector<int>			vec;
	// std::vector<int>::iterator	it;
	// bool						dup;
	// for (int i = 0; i < 5; ++i){
	// 	int	rng = rand() % 100;
	// 	dup = false;
	// 	for (it = vec.begin(); it != vec.end(); ++it){
	// 		if (*it == rng)
	// 			dup = true;
	// 	}
	// 	if (!dup){
	// 		vec.push_back(rng);
	// 		set.insert(rng);
	// 	}
	// 	else
	// 		--i;
	// }

	// for (std::set<int>::iterator	it = set.begin(); it != set.end(); ++it){
	// 	std::cout << *it << std::endl;
	// }

	// std::cout << "\n\n\n\n";

	// for (it = vec.begin(); it != vec.end(); ++it)
	// 	std::cout << *it << std::endl;

	// 		std::cout << "\n\n\n\n";

	// 	std::cout << &(*(set.end())) << std::endl;
	// 	std::cout << &(*(--set.end())) << "    " << *(--set.end()) << std::endl;
	// 	std::cout << &(*(--(--set.end()))) << "    " << *(--(--set.end())) << std::endl;

	return 0;
}