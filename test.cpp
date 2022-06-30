/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:04:17 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/30 15:56:40 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

#include "Vector.hpp"
#include "Integral.hpp"

int	main(void)
{
	srand(time(NULL));

// 	ft::vector<int> ftv;
// 	std::vector<int> stv;
// // 
// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Init\n";
// 	std::cout << "---------------------------------------------------------------\n\n";
// // 
// 	std::cout << "Max size: " << ftv.max_size() << std::endl;
// 	std::cout << "Max size: " << stv.max_size() << "\n\n";
// // 
// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";
// // 
// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";
// // 
// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";
// // 
// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Reserve 50\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	stv.reserve(50);
// 	ftv.reserve(50);

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Reserve 200\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	stv.reserve(200);
// 	ftv.reserve(200);

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "200 capacity push/display back 5RNG\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	for (int i = 0; i < 5; ++i){
// 		int	rng = rand();
// 		stv.push_back(rng);
// 		ftv.push_back(rng);
// 		std::cout << ftv.back() << std::endl;
// 		std::cout << stv.back() << "\n\n";
// 	}

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Reserve 400, redisplay while popback\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	stv.reserve(400);
// 	ftv.reserve(400);

// 	for (int i = 0; i < 5; ++i){
// 		std::cout << ftv.back() << std::endl;
// 		std::cout << stv.back() << "\n\n";
// 		ftv.pop_back();
// 		stv.pop_back();
// 	}

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "5RNG push/display back\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	for (int i = 0; i < 5; ++i){
// 		int	rng = rand();
// 		ftv.push_back(rng);
// 		stv.push_back(rng);
// 		std::cout << ftv.back() << std::endl;
// 		std::cout << stv.back() << "\n\n";
// 	}

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Resize 2, redisplay while popback\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	ftv.resize(2, 0);
// 	stv.resize(2, 0);
	
// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";

// 	for (int i = 0; i < 2; ++i){
// 		std::cout << ftv.back() << std::endl;
// 		std::cout << stv.back() << "\n\n";
// 		ftv.pop_back();
// 		stv.pop_back();
// 	}

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Resize 10 val 42, redisplay while popback\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	ftv.resize(10, 42);
// 	stv.resize(10, 42);

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";

// 	for (int i = 0; i < 10; ++i){
// 		std::cout << ftv.back() << std::endl;
// 		std::cout << stv.back() << "\n\n";
// 		ftv.pop_back();
// 		stv.pop_back();
// 	}

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Front\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	for (int i = 0; i < 5; ++i){
// 		int	rng = rand();
// 		ftv.push_back(rng);
// 		stv.push_back(rng);
// 		std::cout << ftv.front() << std::endl;
// 		std::cout << stv.front() << "\n\n";
// 		ftv.pop_back();
// 		stv.pop_back();
// 	}

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Push_back RNG5, display with at(), []\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	for (int i = 0; i < 5; ++i){
// 		int	rng = rand();
// 		ftv.push_back(rng);
// 		stv.push_back(rng);
// 		std::cout << ftv.at(i) << std::endl;
// 		std::cout << stv.at(i) << "\n\n";
// 		std::cout << ftv[i] << std::endl;
// 		std::cout << stv[i] << "\n\n";
// 	}

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";


// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "Try catch out of range\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	try {ftv.at(5);}
// 	catch (std::out_of_range ret) {std::cout << ret.what() << "\n";};

// 	try {stv.at(5);}
// 	catch (std::out_of_range ret) {std::cout << ret.what() << "\n\n";};

// 	try {ftv.at(-1);}
// 	catch (std::out_of_range ret) {std::cout << ret.what() << "\n";};

// 	try {stv.at(-1);}
// 	catch (std::out_of_range ret) {std::cout << ret.what() << "\n\n";};

// 	std::cout << "---------------------------------------------------------------\n";
// 	std::cout << "RNG10 and clear\n";
// 	std::cout << "---------------------------------------------------------------\n\n";

// 	ftv.resize(10, 42);
// 	stv.resize(10, 42);

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";

// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";

// 	ftv.clear();
// 	stv.clear();

// 	std::cout << "Capacity: " << ftv.capacity() << std::endl;
// 	std::cout << "Capacity: " << stv.capacity() << "\n\n";

// 	std::cout << "Size:     " << ftv.size() << std::endl;
// 	std::cout << "Size:     " << stv.size() << "\n\n";

// 	std::cout << "Empty:    " << ftv.empty() << std::endl;
// 	std::cout << "Empty:    " << stv.empty() << "\n\n";


	// ft::vector<int> ftv1(5, 42);
	// ft::vector<int> ftv2(ftv1);

	// ftv1.push_back(1);
	// ftv2.push_back(1);

	// ftv1.push_back(2);
	// ftv2.push_back(2);

	// ftv1.push_back(1);
	// ftv2.push_back(3);

	// ftv1.push_back(4);
	// ftv2.push_back(4);

	// std::cout << (ftv1 >= ftv2) << std::endl;

	// ftv.swap(stv);

	// ftv.erase(ftv.begin(), ftv.begin());
	// stv.erase(stv.begin(), stv.begin());

	// for (int i = 0; i < 4; ++i){
	// 	ftv.erase(ftv.begin());
	// 	stv.erase(stv.begin());
	// }

	// for (std::vector<int>::iterator	it = stv.begin(); it != stv.end(); ++it){
	// 	std::cout << *it << std::endl;
	// }

	// std::cout << std::endl;

	// for (ft::vector<int>::iterator	it = ftv1.begin(); it != ftv1.end(); ++it){
	// 	std::cout << *it << std::endl;
	// }

	// std::is_integral<int>

	// std::cout << std::endl;
	// std::cout << ftv1.size() << std::endl;
	// std::cout << ftv1.capacity() << std::endl;

	#include <type_traits>

	std::cout << ft::is_integral<volatile const int>::value << "\n";

	// system("leaks a.out");

	return (0);
}
