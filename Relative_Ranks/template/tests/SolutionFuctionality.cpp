#include <gtest/gtest.h>

#include <string>

#include "Solution.h"

class SoltionFunctionality: public ::testing::Test
{
public:
	SoltionFunctionality() = default;

	Solution solution;
};

TEST_F(SoltionFunctionality,
		soltion_should_output_relative_ranks_correctly_for_a_score_empty_list)
{
	// Arange
	std::vector<int> scores;
	std::vector<std::string> expected_ranks;

	// Act
	std::vector result = solution.solution(scores);

	// Assert
	EXPECT_EQ(result, expected_ranks);
}

TEST_F(SoltionFunctionality,
		soltion_should_output_relative_ranks_correctly_for_a_score_list_with_one_element)
{
	// Arange
	std::vector<int> scores{5};
	std::vector<std::string> expected_ranks{"Gold Medal"};

	// Act
	std::vector result = solution.solution(scores);

	// Assert
	EXPECT_EQ(result, expected_ranks);
}

TEST_F(SoltionFunctionality,
		soltion_should_output_relative_ranks_correctly_for_a_score_list_with_two_elements)
{
	// Arange
	std::vector<int> scores{5, 4};
	std::vector<std::string> expected_ranks{"Gold Medal", "Silver Medal"};

	// Act
	std::vector result = solution.solution(scores);

	// Assert
	EXPECT_EQ(result, expected_ranks);
}

TEST_F(SoltionFunctionality,
		soltion_should_output_relative_ranks_correctly_for_a_score_list_with_three_elements)
{
	// Arange
	std::vector<int> scores{5, 3, 1};
	std::vector<std::string> expected_ranks{"Gold Medal", "Silver Medal", "Bronze Medal"};

	// Act
	std::vector result = solution.solution(scores);

	// Assert
	EXPECT_EQ(result, expected_ranks);
}

TEST_F(SoltionFunctionality, soltion_should_output_relative_ranks_correctly_for_a_score_list)
{
	// Arange
	std::vector<int> scores{5, 4, 3, 2, 1};
	std::vector<std::string> expected_ranks{"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};

	// Act
	std::vector result = solution.solution(scores);

	// Assert
	EXPECT_EQ(result, expected_ranks);
}
