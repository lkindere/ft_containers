/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:04:17 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/04 06:52:47 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include <vector>
#include <sys/time.h>

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

template <typename T, typename U> 
bool	iter_fail(T s1, T e1, U s2, U e2)
{
	for (;s1 != e1 && s2 != e2; ++s1, ++s2){
		if (*s1 != *s2)
			return true;
	}
	return false;
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
	bool				rip = false;

	ft::vector<int>		fvec;
	ft::vector<int>		fvec2;
	std::vector<int>	svec;
	std::vector<int>	svec2;

	std::cout << "\nEMPTY/SIZE/CAPACITY/RESIZE:\n";

	for (size_t i = 0; i < RUNS; ++i){
		size_t rng = rand();
		if (rng % 10 > 5)
		{
			fvec.push_back(rng); svec.push_back(rng);
			if (failed(fvec.empty(), svec.empty())
				|| failed(fvec.size(), svec.size())
				|| failed(fvec.capacity(), svec.capacity()))
				rip = true;
		}
		else if (rng % 10 < 3)
		{
			fvec.reserve(rng % 1000); svec.reserve(rng % 1000);
			if (failed(fvec.empty(), svec.empty())
				|| failed(fvec.size(), svec.size())
				|| failed(fvec.capacity(), svec.capacity()))
				rip = true;
		}
		else
			while (svec.size() != 0)
			{
				fvec.pop_back(); svec.pop_back();
				if (failed(fvec.empty(), svec.empty())
					|| failed(fvec.size(), svec.size())
					|| failed(fvec.capacity(), svec.capacity()))
					rip = true;
			}
	}
	status(rip);

	std::cout << "\nACCESS\n";

	for (size_t i = 0; i < RUNS; ++i){
		size_t rng = rand();
		fvec.push_back(rng); svec.push_back(rng);
		size_t	index = (svec.size() - 1) / (rng % 10 + 1);
		if (rng % 4 == 0 && failed(fvec[index], svec[index]))
			rip = true;
		if (rng % 4 == 1 && failed(fvec.at(index), svec.at(index)))
			rip = true;
		if (rng % 4 == 2 && failed (fvec.front(), svec.front()))
			rip = true;
		if (rng % 4 == 3 && failed (fvec.back(), svec.back()))
			rip = true;
	}
	status(rip);

	std::cout << "\nASSIGN/ITER\n";

	for (size_t i = 0; i < RUNS / 100; ++i){
		size_t rng = rand() % 10000;
		fvec.assign(rng, rng); svec.assign(rng, rng);
		if (failed(fvec.empty(), svec.empty())
			|| failed(fvec.size(), svec.size())
			|| failed(fvec.capacity(), svec.capacity())
			|| iter_fail(fvec.begin(), fvec.end(), svec.begin(), svec.end()))
				rip = true;
	}
	status(rip);

	std::cout << "\nERASE/ITER\n";

	while (!svec.empty())
	{
		size_t rng = (rand() % svec.size());
		svec.erase(svec.begin() + rng); fvec.erase(fvec.begin() + rng);
		if (failed(fvec.empty(), svec.empty())
			|| failed(fvec.size(), svec.size())
			|| failed(fvec.capacity(), svec.capacity())
			|| iter_fail(fvec.begin(), fvec.end(), svec.begin(), svec.end()))
				rip = true;
	}
	status(rip);

	std::cout << "\nCLEAR\n";

	svec.clear();
	fvec.clear();
	if (failed(fvec.empty(), svec.empty())
		|| failed(fvec.size(), svec.size())
		|| failed(fvec.capacity(), svec.capacity()))
			rip = true;
	status(rip);

	std::cout << "\nCOMPARISONS\n";

	for (int i = 0; i < RUNS; ++i){
		int	rng = rand();
		fvec.push_back(rng % 10); svec.push_back(rng % 10);
		rng = rand();
		fvec2.push_back(rng % 10); svec2.push_back(rng % 10);
		if (rng % 6 == 0 && failed(fvec == fvec2, svec == svec2))
			rip = true;
		if (rng % 6 == 1 && failed(fvec != fvec2, svec != svec2))
			rip = true;
		if (rng % 6 == 2 && failed(fvec < fvec2, svec < svec2))
			rip = true;
		if (rng % 6 == 3 && failed(fvec > fvec2, svec > svec2))
			rip = true;
		if (rng % 6 == 4 && failed(fvec <= fvec2, svec <= svec2))
			rip = true;
		if (rng % 6 == 5 && failed(fvec >= fvec2, svec >= svec2))
			rip = true;
		if (rng % 10 < 2)
		{
			fvec.clear(); fvec2.clear(); svec.clear(); svec2.clear();
			if (failed(fvec.empty(), svec.empty())
				|| failed(fvec.size(), svec.size())
				|| failed(fvec.capacity(), svec.capacity()))
					rip = true;
		}
	}

	return 0;
}
