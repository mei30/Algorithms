#include "Solution.h"

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <sstream>

int Solution::solution(std::vector<char>& tasks, int n)
{
	std::map<int, int> task_segments;
	for (auto iterator{tasks.begin()}; iterator != tasks.end(); ++iterator)
		++task_segments[*iterator];

	std::priority_queue<int> task_prioritizer;

	for (const auto& [key, value] : task_segments)
		task_prioritizer.push(value);

	uint64_t cpu_time_unit_count = 0;
	while (!task_prioritizer.empty())
	{

		std::vector<int> v;

		for (int i{0}; i <=n; ++i)
		{
			if (!task_prioritizer.empty())
			{
				v.push_back(task_prioritizer.top());
				task_prioritizer.pop();
			}
		}

		for (auto it{v.begin()}; it != v.end(); ++it)
		{
			--(*it);
			if (*it > 0)
				task_prioritizer.push(*it);
		}

		cpu_time_unit_count += task_prioritizer.empty()? v.size() : n + 1;
	}

	return cpu_time_unit_count;
}
