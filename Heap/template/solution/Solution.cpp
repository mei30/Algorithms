#include "Solution.h"

#include <iostream>
#include <iterator>
#include <cmath>

void Heap::heapify(int element)
{
	Iterator inserted_iterator =
			_underlying_type.insert(_underlying_type.begin(), element);

	int inserted_index =
			std::distance(_underlying_type.begin(), inserted_iterator);
	int parent_index = floor(inserted_index / 2);

	while (parent_index != 0)
	{
		auto& parent_element = _underlying_type[parent_index];
		auto& child_element = _underlying_type[inserted_index];

		if (parent_element > child_element)
			std::swap(parent_element, child_element);

		parent_index = floor(parent_index / 2);
	}
}

int Heap::top() const
{
	if (_underlying_type.empty())
		throw std::out_of_range("The heap is empty");
	return *_underlying_type.begin();
}

void Heap::pop()
{
	if (_underlying_type.empty())
		throw std::out_of_range("The heap is empty");

	int last_element_index = _underlying_type.size() - 1;

	/*
	 * In order to do not distrupt the completeness of binary-tree
	 * we should swap last and root element then re-order the heap again
	 * and then remove the last element(ie the topest element)
	 */
	_underlying_type[0] = _underlying_type[last_element_index];
	_underlying_type.pop_back();

	auto ith_left_child_index = [](int i) { return 2 * i + 1;};
	auto ith_right_child_index = [](int i) { return 2 * i + 2;};

	int current_index = 0;
	while ((ith_left_child_index(current_index)) <= _underlying_type.size() - 1)
	{
		const int right_child_index = ith_right_child_index(current_index);
		const int left_child_index = ith_left_child_index(current_index);

		int swapped_index;
		if (right_child_index <= _underlying_type.size() - 1)
		{
			if (_underlying_type[left_child_index] > _underlying_type[right_child_index])
				swapped_index = left_child_index;
			else
				swapped_index = right_child_index;
		}
		else
			swapped_index = left_child_index;

		auto& parent_element = _underlying_type[current_index];
		auto& swapped_element = _underlying_type[swapped_index];

		if (swapped_element > parent_element)
		{
			std::swap(parent_element, swapped_element);
			current_index = swapped_index;
		}
		else
			break;
	}
}
