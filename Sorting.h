#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <list>
#include <iostream>

// A namespace where user-defined sorting algorithms exist
namespace Sorting{

	std::vector<int> bubble_sort(std::vector<int> A);
	std::vector<int> selection_sort(std::vector<int> A);
	std::vector<int> insertion_sort(std::vector<int> A);
	std::vector<int> merge_sort(std::vector<int> A);
	std::vector<int> merge(std::vector<int> ALeft, std::vector<int> ARight);
	std::vector<int> quick_sort(std::vector<int> A, int left = 0, int right = -100);
	void quick_sort_in_place(std::vector<int>& A, int left = 0, int right = -100);
	int partition(std::vector<int>& A, int left, int right);
	std::vector<int> counting_sort(std::vector<int> A);
	std::vector<int> radix_sort(std::vector<int> A, int base = 10);
	std::vector<float> bucket_sort(std::vector<float> A);

	template<typename T>
	void print_vector(std::vector<T> A);

}

// function to print out contents of the vector A
template<typename T>
void Sorting::print_vector(std::vector<T> A){
	for (int i = 0; i < A.size(); i++){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

#endif