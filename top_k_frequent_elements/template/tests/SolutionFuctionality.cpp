#include <gtest/gtest.h>

#include "Solution.h"

class SoltionFunctionality: public ::testing::Test
{
public:
	SoltionFunctionality() = default;

	Solution solution;
};

TEST_F(SoltionFunctionality,
		solution_sholud_return_top_k_frequent_elements_correctly_for_a_specific_list)
{
	// Arrange
	std::vector<int> numbers{1, 1, 1, 2, 2, 2, 4, 4};

	int k = 2;

	std::vector<int> expected_result{1, 2};

	// Act
	auto result = solution.solution(numbers, k);

	// Assert
	EXPECT_EQ(expected_result, result);
}

TEST_F(SoltionFunctionality,
		solution_sholud_return_top_k_frequent_elements_correctly_for_a_specific_list_with_negetive_numbers)
{
	// Arrange
	std::vector<int> numbers{-1, -1, -1, -2, -2, -2, -4, -4};

	int k = 2;

	std::vector<int> expected_result{-2, -1};

	// Act
	auto result = solution.solution(numbers, k);

	// Assert
	EXPECT_EQ(expected_result, result);
}
