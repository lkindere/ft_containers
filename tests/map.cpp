/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:10:02 by lkindere          #+#    #+#             */
/*   Updated: 2022/07/15 15:34:50 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <iostream>
#include <map>

#include "../Map.hpp"

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

template <typename T, typename A>
std::pair<T, A>	pair(const T& x, const A& y)
{
	return (std::make_pair(x, y));
}

template <typename T, typename A>
ft::pair<T, A>	fpair(const T& x, const A& y)
{
	return (ft::make_pair(x, y));
}

int	main(void)
{
	srand(time(NULL));
	bool					rip = false;

	ft::map<int, float>		fmap;
	ft::map<int, float>		fmap2;

	std::map<int, float>	smap;
	std::map<int, float>	smap2;


	std::cout << "\nEMPTY/SIZE/INSERT/ERASE:\n";

	for (int i = 0; i < RUNS; ++i){
		int rng = rand();
		if (rng % 10 > 2)
		{
			fmap.insert(fpair(rng, rng)); smap.insert(pair(rng, rng));
			if (failed(fmap.empty(), smap.empty())
				|| failed(fmap.size(), smap.size()))
				rip = true;
		}
		else
			while (smap.size() != 0)
			{
				fmap.erase(fmap.begin()); smap.erase(smap.begin());
				if (failed(fmap.empty(), smap.empty())
					|| failed(fmap.size(), smap.size()))
					rip = true;
			}
	}
	status(rip);

	std::cout << "\nFIND/[]/COUNT\n";

	for (int i = 0; i < RUNS / 5; ++i){
		int rng = rand();
		fmap.insert(fpair(rng, rng)); smap.insert(pair(rng, rng));
	}
	for (int i = 0; i < RUNS; ++i){
		int rng = rand();
		if (rng % 10 > 7)
		{
			if (smap.find(rng) == smap.end())
			{
				if (failed(fmap.find(rng) == fmap.end(), smap.find(rng) == smap.end()))
					rip = true;
			}
			else if (failed(smap.find(rng)->first, fmap.find(rng)->first))
				rip = true;
		}
		if (rng % 10 < 3)
		{
			rng = rng % (smap.size() - 1);
			if (failed(smap[rng], fmap[rng]))
				rip = true;
		}
		else 
			if (failed(smap.count(rng), fmap.count(rng)))
				rip = true;
	}
	status(rip);

	std::cout << "\nCONTENT CHECK\n";
	if (failed(smap.size(), fmap.size()) || failed(smap.empty(), fmap.empty()))
		rip = true;
	{
		ft::map<int, float>::iterator	fbegin = fmap.begin();
		ft::map<int, float>::iterator	fend = fmap.end();
		std::map<int, float>::iterator	sbegin = smap.begin();
		std::map<int, float>::iterator	send = smap.end();
		while (sbegin != send)
		{
			if (failed(sbegin->first, fbegin->first))
				rip = true;
			++sbegin; ++fbegin;
		}
	}
	status(rip);

	std::cout << "\nCLEAR\n";

	smap.clear(); fmap.clear();
	if (failed(smap.size(), fmap.size()) || failed(smap.empty(), fmap.empty())
		|| failed(smap.begin() == smap.end(), fmap.begin() == fmap.end()))
		rip = true;
	status(rip);

	std::cout << "\nTIMER\n";
	double	start;
	
	std::cout << "FT:  ";

	start = get_time();
	for (size_t i = 0; i < RUNS; ++i)
		fmap.insert(fpair(rand(), rand()));
	while (!fmap.empty())
		fmap.erase(fmap.begin());
	std::cout <<  get_time() - start << "ms" << std::endl;

	std::cout << "STD: ";
	
	start = get_time();
	for (size_t i = 0; i < RUNS; ++i)
		smap.insert(pair(rand(), rand()));
	while (!fmap.empty())
		smap.erase(smap.begin());
	std::cout <<  get_time() - start << "ms" << std::endl;

	system("leaks a.out");
	return 0;
}
