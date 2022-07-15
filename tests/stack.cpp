/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 03:22:02 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 15:11:20 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <iostream>
#include <stack>
#include <vector>

#include "../Stack.hpp"

#define	RUNS 1000000

void	status(bool &rip)
{
	if (rip == true)
		std::cout << "KO\n";
	else
		std::cout << "OK\n";
	rip = false;
}

template <typename T>
bool	failed(T a, T b, T c)
{
	if (a == b && b == c)
		return false;
	return true;
}

double	get_time(void)
{
	timeval	time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

int	main(void)
{
	srand(time(NULL));
	bool			rip = false;

	ft::stack<int>	fstack;
	ft::stack<int>	fstack2;


	std::stack<int>	sstack;
	std::stack<int>	sstack2;

	ft::stack<int, std::vector<int> >	hstack;
	ft::stack<int, std::vector<int> >	hstack2;


	std::cout << "\nEMPTY/SIZE/POP:\n";

	for (int i = 0; i < RUNS; ++i){
		int rng = rand();
		if (rng % 10 > 2)
		{
			fstack.push(rng); sstack.push(rng); hstack.push(rng);
			if (failed(fstack.empty(), sstack.empty(), hstack.empty())
				|| failed(fstack.size(), sstack.size(), hstack.size()))
				rip = true;
		}
		else
			while (sstack.size() != 0)
			{
				fstack.pop(); sstack.pop(); hstack.pop();
				if (failed(fstack.empty(), sstack.empty(), hstack.empty())
					|| failed(fstack.size(), sstack.size(), hstack.size()))
					rip = true;
			}
	}
	status(rip);
	
	std::cout << "\nPUSH/TOP\n";

	for (int i = 0; i < RUNS; ++i){
		int	rng = rand();
		fstack.push(rng); sstack.push(rng); hstack.push(rng);
		if (failed(fstack.top(), sstack.top(), hstack.top()))
			rip = true;
	}
	status(rip);

	while (!sstack.empty()){
		sstack.pop(); fstack.pop(); hstack.pop();
	}

	std::cout << "\nCOMPARISONS\n";

	for (int i = 0; i < RUNS; ++i){
		int	rng = rand();
		fstack.push(rng % 10); sstack.push(rng % 10); hstack.push(rng % 10);
		rng = rand();
		fstack2.push(rng % 10); sstack2.push(rng % 10); hstack2.push(rng % 10);
		if (rng % 6 == 0 && failed(fstack == fstack2, sstack == sstack2, hstack == hstack2))
			rip = true;
		if (rng % 6 == 1 && failed(fstack != fstack2, sstack != sstack2, hstack != hstack2))
			rip = true;
		if (rng % 6 == 2 && failed(fstack < fstack2, sstack < sstack2, hstack < hstack2))
			rip = true;
		if (rng % 6 == 3 && failed(fstack > fstack2, sstack > sstack2, hstack > hstack2))
			rip = true;
		if (rng % 6 == 4 && failed(fstack <= fstack2, sstack <= sstack2, hstack <= hstack2))
			rip = true;
		if (rng % 6 == 5 && failed(fstack >= fstack2, sstack >= sstack2, hstack >= hstack2))
			rip = true;
		if (rng % 10 < 2)
			while (sstack.size() != 0)
			{
				fstack.pop(); sstack.pop(); hstack.pop();
				fstack2.pop(); sstack2.pop(); hstack2.pop();
				if (failed(fstack.empty(), sstack.empty(), hstack.empty())
					|| failed(fstack.size(), sstack.size(), hstack.size()))
					rip = true;
			}
	}
	status(rip);

	std::cout << "\nTIMER\n";
	double	start;
	
	std::cout << "FT:  ";

	start = get_time();
	for (size_t i = 0; i < RUNS * 5; ++i)
		fstack.push(1);
	while (!fstack.empty())
		fstack.pop();
	std::cout <<  get_time() - start << "ms" << std::endl;

	std::cout << "STD: ";
	
	start = get_time();
	for (size_t i = 0; i < RUNS * 5; ++i)
		sstack.push(1);
	while (!fstack.empty())
		sstack.pop();
	std::cout <<  get_time() - start << "ms" << std::endl;

	std::cout << "HYB: ";
	
	start = get_time();
	for (size_t i = 0; i < RUNS * 5; ++i)
		hstack.push(1);
	while (!fstack.empty())
		hstack.pop();
	std::cout <<  get_time() - start << "ms" << std::endl;

	system("leaks a.out");
	return 0;
}
