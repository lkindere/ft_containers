/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:11:58 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 15:34:53 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <iostream>
#include <set>

#include "../Set.hpp"

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
bool	failed(T a, T b)
{
	if (a == b)
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

	ft::set<int>	fset;
	ft::set<int>	fset2;

	std::set<int>	sset;
	std::set<int>	sset2;


	std::cout << "\nEMPTY/SIZE/INSERT/ERASE:\n";

	for (int i = 0; i < RUNS; ++i){
		int rng = rand();
		if (rng % 10 > 2)
		{
			fset.insert(rng); sset.insert(rng);
			if (failed(fset.empty(), sset.empty())
				|| failed(fset.size(), sset.size()))
				rip = true;
		}
		else
			while (sset.size() != 0)
			{
				fset.erase(fset.begin()); sset.erase(sset.begin());
				if (failed(fset.empty(), sset.empty())
					|| failed(fset.size(), sset.size()))
					rip = true;
			}
	}
	status(rip);

	std::cout << "\nFIND/COUNT\n";

	for (int i = 0; i < RUNS / 5; ++i){
		int rng = rand();
		fset.insert(rng); sset.insert(rng);
	}
	for (int i = 0; i < RUNS; ++i){
		int rng = rand();
		if (rng % 10 > 5)
		{
			if (sset.find(rng) == sset.end())
			{
				if (failed(fset.find(rng) == fset.end(), sset.find(rng) == sset.end()))
					rip = true;
			}
			else if (failed(*sset.find(rng), *fset.find(rng)))
				rip = true;
		}
		else 
			if (failed(sset.count(rng), fset.count(rng)))
				rip = true;
	}
	status(rip);

	std::cout << "\nCONTENT CHECK\n";
	if (failed(sset.size(), fset.size()) || failed(sset.empty(), fset.empty()))
		rip = true;
	{
		ft::set<int>::iterator	fbegin = fset.begin();
		ft::set<int>::iterator	fend = fset.end();
		std::set<int>::iterator	sbegin = sset.begin();
		std::set<int>::iterator	send = sset.end();
		while (sbegin != send)
		{
			if (failed(*sbegin, *fbegin))
				rip = true;
			++sbegin; ++fbegin;
		}
	}
	status(rip);

	std::cout << "\nCLEAR\n";

	sset.clear(); fset.clear();
	if (failed(sset.size(), fset.size()) || failed(sset.empty(), fset.empty())
		|| failed(sset.begin() == sset.end(), fset.begin() == fset.end()))
		rip = true;
	status(rip);

	std::cout << "\nTIMER\n";
	double	start;
	
	std::cout << "FT:  ";

	start = get_time();
	for (size_t i = 0; i < RUNS; ++i)
		fset.insert(rand());
	while (!fset.empty())
		fset.erase(fset.begin());
	std::cout <<  get_time() - start << "ms" << std::endl;

	std::cout << "STD: ";
	
	start = get_time();
	for (size_t i = 0; i < RUNS; ++i)
		sset.insert(rand());
	while (!fset.empty())
		sset.erase(sset.begin());
	std::cout <<  get_time() - start << "ms" << std::endl;

	system("leaks a.out");
	return 0;
}
