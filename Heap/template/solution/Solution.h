#ifndef SOLUTION
#define SOLUTION

#include <vector>
#include <deque>

class Heap
{
	public:
		using UnderLyingType = std::deque<int>;

		using ConstIterator = UnderLyingType::const_iterator;
		using Iterator = UnderLyingType::iterator;

		Heap() = default;

		void heapify(int element);

		void pop();
		int top() const;

	private:
		UnderLyingType _underlying_type;
};

#endif
