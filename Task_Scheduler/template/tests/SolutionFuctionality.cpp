#include <gtest/gtest.h>

#include "Solution.h"

class SoltionFunctionality: public ::testing::Test
{
public:
	SoltionFunctionality() = default;

	Solution solution;
};

TEST_F(SoltionFunctionality,
		task_scheduler_should_return_correct_cpu_time_units_for_a_specific_tasks)
{
	// Arange
	std::vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
	int n = 2;
	int expected_cpu_time_unit_count = 8;

	// Act
	int actual_cpu_time_unit_count = solution.solution(tasks, n);

	// Assert
	EXPECT_EQ(actual_cpu_time_unit_count, expected_cpu_time_unit_count);
}

TEST_F(SoltionFunctionality,
		task_scheduler_should_return_correct_cpu_time_units_for_a_unique_tasks)
{
	// Arange
	std::vector<char> tasks{'A', 'A', 'A'};
	int n = 2;
	int expected_cpu_time_unit_count = 7;

	// Act
	int actual_cpu_time_unit_count = solution.solution(tasks, n);

	// Assert
	EXPECT_EQ(actual_cpu_time_unit_count, expected_cpu_time_unit_count);
}

TEST_F(SoltionFunctionality,
		task_scheduler_should_return_correct_cpu_time_units_for_more_than_two_unique_tasks)
{
	// Arange
	std::vector<char> tasks{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int n = 2;
	int expected_cpu_time_unit_count = 16;

	// Act
	int actual_cpu_time_unit_count = solution.solution(tasks, n);

	// Assert
	EXPECT_EQ(actual_cpu_time_unit_count, expected_cpu_time_unit_count);
}
