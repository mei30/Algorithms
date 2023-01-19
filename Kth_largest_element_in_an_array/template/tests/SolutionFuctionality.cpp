#include <gtest/gtest.h>

#include "Solution.h"

class SoltionFunctionality: public ::testing::Test
{
public:
	SoltionFunctionality() = default;

	Solution solution;
};

TEST_F(SoltionFunctionality, kth_largest_element_should_return_correctly_for_a_specific_list)
{
	// Arrange
	std::vector<int> numbers{3, 2, 1, 5, 6, 4};

	int k = 2;
	int kth_largest_element = 5;

	// Act
	int result = solution.solution(numbers, k);

	// Assert
	EXPECT_EQ(result, kth_largest_element);
}

TEST_F(SoltionFunctionality,
		kth_largest_element_should_return_correctly_for_a_specific_list_with_duplicates)
{
	// Arrange
	std::vector<int> numbers{3, 2, 3, 1, 2, 4, 5, 5, 6};

	int k = 4;
	int kth_largest_element = 4;

	// Act
	int result = solution.solution(numbers, k);

	// Assert
	EXPECT_EQ(result, kth_largest_element);
}

TEST_F(SoltionFunctionality,
		kth_largest_element_should_return_correctly_for_a_specific_list_when_k_is_equal_to_size_of_list)
{
	// Arrange
	std::vector<int> numbers{-1, 2, 0};

	int k = 3;
	int kth_largest_element = -1;

	// Act
	int result = solution.solution(numbers, k);

	// Assert
	EXPECT_EQ(result, kth_largest_element);
}
