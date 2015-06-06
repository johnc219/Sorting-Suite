#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

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
	template<typename T>
	void fill_vector(std::vector<T>& A, int length, T lower, T upper);
	template<typename T>
	bool is_sorted(std::vector<T> A);

}

// function to print out contents of the vector A
template<typename T>
void Sorting::print_vector(std::vector<T> A){
	for (int i = 0; i < A.size(); i++){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

// function to fill a vector with random numbers
template<typename T>
void Sorting::fill_vector(std::vector<T>& A, int length, T lower, T upper){

	A.clear();
	T range = upper - lower;
	for (int i = 0; i < length; i++){
		T num = static_cast<T>( lower + (rand() / (RAND_MAX / range)) );
		A.push_back(num);
	}
}

// function to check if a vector is sorted
template<typename T>
bool Sorting::is_sorted(std::vector<T> A){
	for (int i = 1; i < A.size(); i++){
		if (A[i] < A[i-1]){
			return false;
		}
	}
	return true;
}

#endif