#include "Solution.h"

#include <iostream>
#include <map>
#include <algorithm>

std::vector<int> Solution::solution(std::vector<int> numbers, int k)
{
	std::map<int, int> frequencies;
	for (auto iteraotr{numbers.begin()}; iteraotr != numbers.end(); ++iteraotr)
		++frequencies[*iteraotr];

	std::vector<std::pair<int, int>> numbers_with_most_frequencies;

	for (auto const& [key, value] : frequencies)
		numbers_with_most_frequencies.push_back({key, value});

	std::nth_element(numbers_with_most_frequencies.begin(),
			numbers_with_most_frequencies.begin() + k - 1,
			numbers_with_most_frequencies.end(),
					 [](auto a, auto b) {return a.second > b.second;});

	std::vector<int> top_k;
	for (auto i{0}; i <= k - 1; ++i)
		top_k.push_back(numbers_with_most_frequencies[i].first);

	return top_k;
}
