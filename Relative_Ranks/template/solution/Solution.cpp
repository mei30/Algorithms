#include "Solution.h"

#include <iostream>
#include <algorithm>
#include <iterator>

using std::vector;
using std::string;
using std::pair;

std::vector<std::string> Solution::solution(std::vector<int>& scores)
{
	std::vector<std::pair<int, int>> scores_to_its_position{scores.size()};

	for (auto i{0}; i < scores.size(); ++i)
		scores_to_its_position[i] = {scores[i], i};

	std::sort(scores_to_its_position.begin(), scores_to_its_position.end(),
			  [](auto a, auto b) { return a.first >= b.first; });

	vector<string> result{scores.size()};

	for (auto iterator{scores_to_its_position.begin()};
		 iterator != scores_to_its_position.end(); ++iterator)
	{
		auto index = std::distance(scores_to_its_position.begin(), iterator);
		switch (index)
		{
		case 0:
			result[iterator->second] = "Gold Medal";
			break;
		case 1:
			result[iterator->second] = "Silver Medal";
			break;
		case 2:
			result[iterator->second] = "Bronze Medal";
			break;
		default:
			result[iterator->second] = std::to_string(index + 1);
		}
	}

	return result;
}
