/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:48 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/07 19:12:27 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"
#include <iostream>
#include <vector>

/*
																			P

													SIBLING IS ON THE LEFT
		
														HAS RED CHILD
													<					>
									RED IS LEFT								RED IS RIGHT
		/ case RR(P)																				< case	RR(S)	LR(P)
		S color = P color																					S->left color = P color
	S->left color = S color
					



												P

													SIBLING IS ON THE RIGHT
		
														HAS RED CHILD
													<					>
									RED IS LEFT								RED IS RIGHT
																								\ case LR(P)
			<	RR(S) 	LR(P)
			S->right color = P color																	S color = P color
																							S->right color = S color




																			P
													SIBLING IS ON THE LEFT 
													HAS NO RED CHILD
													LR(S)	RR(P)	


												P	
													SIBLING IS ON THE RIGHT
													HAS NO RED CHILD
														LR(P)


											S HAS 2 BLACK CHILDREN RECOLOR S TO RED
														REPEAT FROM P
										P																			P

								LR(P)			S IS RED and right									S IS RED and left			RR(P)
																		


																P IS RED				NEW S IS BLACK
										
													
																	
*/


int	main(void)
{
	srand(time(NULL));
	ft::tree<int, ft::pair<int, float> >	tree;

	// {
	// 	std::cout << "S is right of P, red is right"
	// 	tree.root_ = tree.allocNode(ft::make_pair(30, 5.5));
	// 	tree.root_->right = tree.allocNode(ft::make_pair(40, 5.5), tree.root_);
	// 	tree.root_->right->left = tree.allocNode(ft::make_pair(35, 5.5), tree.root_->right);
	// 	tree.root_->right->right = tree.allocNode(ft::make_pair(50, 5.5), tree.root_->right);
	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.leftRotate(tree.root_);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
	// }

	// {
	// 	std::cout << "S is right of P, red is left";
	// 	tree.root_ = tree.allocNode(ft::make_pair(30, 5.5));
	// 	tree.root_->right = tree.allocNode(ft::make_pair(40, 5.5), tree.root_);
	// 	tree.root_->right->left = tree.allocNode(ft::make_pair(35, 5.5), tree.root_->right);
	// 	tree.printTree();
	// 	std::cout << "\n\n";

	// 	tree.rightRotate(tree.root_->right);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
		
	// 	tree.leftRotate(tree.root_);
	// 	tree.printTree();
	// 	std::cout << "\n\n";
	// }

	

	// tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// 	tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// 	tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// 	tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

	// 	tree.remove(tree.root_->right);
	// tree.printTree();
	// std::cout << "\n\n";

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

	// std::vector<int>			vec;
	// std::vector<int>::iterator	it;
	// bool						dup;
	// for (int i = 0; i < 10000; ++i){
	// 	int	rng = rand() % 10000;
	// 	dup = false;
	// 	for (it = vec.begin(); it != vec.end(); ++it){
	// 		if (*it == rng)
	// 			dup = true;
	// 	}
	// 	if (!dup){
	// 		vec.push_back(rng);
	// 		std::cout << "Inserting " << rng << std::endl;
	// 		tree.insertNode(ft::make_pair(rng, 5.5));
	// 		tree.printTree();
	// 		std::cout << "\n\n";
	// 	}
	// }
	// tree.printTree();
	system("leaks a.out");
	return 0;
}