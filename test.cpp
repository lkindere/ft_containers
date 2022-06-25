/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:04:17 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/25 16:58:28 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <memory>
#include <iostream>

#include "ft_vector.hpp"

int	main(void)
{
	ft::vector<int> ftv;
	std::vector<int> stv;

	std::cout << "Init----------------------------------------\n\n";

	std::cout << "Max size: " << ftv.max_size() << std::endl;
	std::cout << "Max size: " << stv.max_size() << "\n\n";

	std::cout << "Capacity: " << ftv.capacity() << std::endl;
	std::cout << "Capacity: " << stv.capacity() << "\n\n";

	std::cout << "Size:     " << ftv.size() << std::endl;
	std::cout << "Size:     " << stv.size() << "\n\n";

	std::cout << "Empty:    " << ftv.empty() << std::endl;
	std::cout << "Empty:    " << stv.empty() << "\n\n";

	std::cout << "Reserve 50----------------------------------\n\n";

	stv.reserve(50);
	ftv.reserve(50);

	std::cout << "Capacity: " << ftv.capacity() << std::endl;
	std::cout << "Capacity: " << stv.capacity() << "\n\n";

	std::cout << "Size:     " << ftv.size() << std::endl;
	std::cout << "Size:     " << stv.size() << "\n\n";


	std::cout << "Empty:    " << ftv.empty() << std::endl;
	std::cout << "Empty:    " << stv.empty() << "\n\n";

	ftv.reserve(45);
	ftv.reserve(200);
	std::cout << "Capacity: " << ftv.capacity() << std::endl;


	// system("leaks a.out");
	return (0);
}