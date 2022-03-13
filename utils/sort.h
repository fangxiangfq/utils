#pragma once
#include <algorithm>

NameSpace_Beg(utils)

template<typename It, typename Comp = std::less<typename It::value_type>>
void heapfy(const It& beg, const It& cur, const It& end)
{
	if (cur < beg) {
		return;
	}

	if (cur >= end) {
		return;
	}

	auto parent = cur;
	auto max = parent;

	if (std::distance(cur, end) > std::distance(beg, cur) + 1) {
		auto left = parent + std::distance(beg, cur) + 1;
		if (Comp()(*left, *max)) {
			max = left;
		}
	}

	if (std::distance(cur, end) > std::distance(beg, cur) + 2) {
		auto right = parent + std::distance(beg, cur) + 2;
		if (Comp()(*right, *max)) {
			max = right;
		}
	}

	if (max != parent) {
		std::iter_swap(max, parent);
		heapfy(beg, max, end);
	}
}

template<typename It, typename Comp = std::less<typename It::value_type>>
void make_heap(const It& beg, const It& end)
{
	if (beg >= end) {
		return;
	}

	auto size = std::distance(beg, end);
	for (It it = beg + size / 2 - 1; it > beg; --it) {
		heapfy<It, Comp>(beg, it, end);
	}

	heapfy<It, Comp>(beg, beg, end);
}

template<typename It, typename Comp = std::less<typename It::value_type>>
void heap_sort(const It& beg, const It& end)
{
	if (beg >= end) {
		return;
	}

	make_heap<It, Comp>(beg, end);
	auto pos = beg - beg + 1;
	for (auto it = beg; it != end; ++it) {
		std::iter_swap(beg, end - pos);
		heapfy<It, Comp>(beg, beg, end - pos);
		pos++;
	}
}

NameSpace_End(utils)




