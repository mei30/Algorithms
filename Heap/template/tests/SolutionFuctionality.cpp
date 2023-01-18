#include <gtest/gtest.h>

#include "Solution.h"
#include <queue>

class MaxHeapFunctionality: public ::testing::Test
{
public:
	MaxHeapFunctionality() = default;

	Heap<int> heap;
};

TEST_F(MaxHeapFunctionality,
		heap_sould_always_get_the_topest_element_after_adding_multiple_elements)
{
	// Arrange
	int topest = 80;

	// Action
	heap.heapify(10);
	heap.heapify(20);
	heap.heapify(30);
	heap.heapify(40);
	heap.heapify(topest);

	// Assert
	EXPECT_EQ(topest, heap.top());
}

TEST_F(MaxHeapFunctionality,
		getting_top_of_heap_if_heap_is_empty_heap_should_throw_out_of_range_exception)
{
	// Assert
	EXPECT_THROW(heap.top(), std::out_of_range);
}

TEST_F(MaxHeapFunctionality,
		poping_from_empty_heap_should_throw_out_of_range_exception)
{
	// Assert
	EXPECT_THROW(heap.top(), std::out_of_range);
}

TEST_F(MaxHeapFunctionality,
		consecutive_heapify_and_poping_from_heap_should_get_the_right_topest_element)
{
	// Act
	heap.heapify(10);
	heap.heapify(30);
	heap.heapify(20);
	heap.heapify(50);
	heap.heapify(40);
	heap.heapify(80);

	// Assert
	EXPECT_EQ(heap.top(), 80);

	// Act
	heap.pop();

	// Assert
	EXPECT_EQ(heap.top(), 50);

	// Act
	heap.pop();

	// Assert
	EXPECT_EQ(heap.top(), 40);

	// Act
	heap.pop();

	// Assert
	EXPECT_EQ(heap.top(), 30);

	// Act
	heap.pop();
	heap.pop();

	// Assert
	EXPECT_EQ(heap.top(), 10);
}
