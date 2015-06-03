#ifndef SORTING_H
#define SORTING_H

#include <vector>

// A namespace where user-defined sorting algorithms exist
namespace Sorting{

	std::vector<int> bubble_sort(std::vector<int> A);
	std::vector<int> selection_sort(std::vector<int> A);
	std::vector<int> insertion_sort(std::vector<int> A);
	std::vector<int> merge_sort(std::vector<int> A);
	std::vector<int> merge(std::vector<int> ALeft, std::vector<int> ARight);

}

#endif