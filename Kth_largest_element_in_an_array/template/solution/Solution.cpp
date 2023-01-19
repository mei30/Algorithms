#include "Solution.h"

#include <iostream>
#include <algorithm>

int Solution::solution(std::vector<int> numbers, int k)
{
	std::nth_element(numbers.begin(), numbers.begin() + k - 1, numbers.end(),
			std::greater<int>{});

	return numbers[k -  1];
}
