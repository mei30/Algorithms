#ifndef SOLUTION
#define SOLUTION

#include <vector>
#include <deque>
#include <functional>

template <typename T, class Allocator = std::allocator<T>, class Comparator = std::greater<T>>
class Heap
{
	public:
		using UnderLyingType = std::deque<T, Allocator>;

		using ConstIterator = typename UnderLyingType::const_iterator;
		using Iterator = typename UnderLyingType::iterator;

		Heap() = default;
		Heap(const Heap& source) = default;
		Heap(Heap&& source) = default;

		~Heap() = default;

		Heap& operator=(const Heap& source) = default;
		Heap& operator=(Heap&& source) = default;

		void heapify(T element);

		void pop();
		T top() const;

		inline typename UnderLyingType::size_type get_size() const noexcept
		{
			_underlying_type.size();
		}

	private:
		UnderLyingType _underlying_type;
};

#endif
