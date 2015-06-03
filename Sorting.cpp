#include "Sorting.h"

/************************************  bubble_sort  *************************************/

// worst case	Theta(n^2)
// best case	Theta(n)
std::vector<int> Sorting::bubble_sort(std::vector<int> A){

	// outer loop, after one loop one value will be in correct place
	for (int i = 0; i < A.size(); i++){
		bool swapped = false;

		// inner loop, swap adjacent items if left one is greater than right one 
		for (int j = 0; j < A.size()-1; j++){
			if (A[j] > A[j+1]){
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				swapped = true;
			}
		}

		// break outer loop if no changes were made in the outer loop iteration (sorting finished)
		if (!swapped){
			break;
		}
	}

	// A is now sorted
	return A;
}

/************************************  selection_sort  *************************************/

// worst case	Theta(n^2)
// best case	Theta(n^2)
std::vector<int> Sorting::selection_sort(std::vector<int> A){

	// get the index of the minimum value between the i'th value and the last value
	for (int i = 0; i < A.size()-1; i++){
		int min = i;

		// update the minimum index if we find a smaller value than the value at the current min index
		for (int j = i + 1; j < A.size(); j++){
			if (A[j] < A[min]){
				min = j;
			}
		}

		// swap the i'th value with minimum value found in this iteration
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}

	// A is now sorted
	return A;
}

/************************************  insertion_sort  *************************************/

// worst case:	Theta(n^2)
// best case:	Theta(n)
std::vector<int> Sorting::insertion_sort(std::vector<int> A){

	// "insert" each value starting from the 2nd value in the array
	for (int i = 1; i < A.size(); i++){

		// save a copy of the i'th value so we can place it accordingly at the end of the iteration
		int val = A[i];

		// look at the values to the left of 'i' and shift values one to the right until we see a value less than our stored copy or until we've shifted all values
		int j = i - 1;
		while (j >= 0 && A[j] > val){
			A[j+1] = A[j];
			j--;
		}

		// 'j+1' holds the index where the copy should be placed. Everything to the left of this index is sorted. 
		A[j+1] = val;
	}

	// A is now sorted
	return A;
}

/************************************  merge_sort  *************************************/

// worst case:	Theta(nlogn)
// best case:	Theta(nlogn)
std::vector<int> Sorting::merge_sort(std::vector<int> A){
	
	// stop recursively calling once the argument is of size 1, and return that 1-item argument
	if (A.size() == 1){
		return A;
	}

	// otherwise, split the argument into two vectors
	int middle = (A.size()+1) / 2;
	std::vector<int> ALeft(A.begin(), A.begin()+middle);
	std::vector<int> ARight(A.begin()+middle, A.end());

	// recursively call merge_sort on each half of the argument
	ALeft = Sorting::merge_sort(ALeft);
	ARight = Sorting::merge_sort(ARight);

	// merge the two sorted halves into one sorted vector
	return Sorting::merge(ALeft, ARight);
}

std::vector<int> Sorting::merge(std::vector<int> ALeft, std::vector<int> ARight){
	
	// The merged vector that will be sorted (as long as the arguments are sorted)
	std::vector<int> result;
	
	// Method 1
	// advantage: the push_back method is amortized constant time
	//			  and as a result, the merge operation takes only Theta(n)
	
	// keep track of the size of each "half" (the left vector and the right vector)
	int ALSize = ALeft.size();
	int ARSize = ARight.size();

	// keep track of which values in each vector are to be pushed_back next into the result
	int ALIndex = 0;
	int ARIndex = 0;

	// keep on pushing values into the result while there are any that haven't been pushed yet
	while (ALSize > 0 || ARSize > 0){
		
		// if both halves still have values to be pushed, push the smaller one. If they're equal, push both
		if (ALSize > 0 && ARSize > 0){
			if (ALeft[ALIndex] < ARight[ARIndex]){
				result.push_back(ALeft[ALIndex]);
				ALSize--;
				ALIndex++;
			} else if (ALeft[ALIndex] > ARight[ARIndex]){
				result.push_back(ARight[ARIndex]);
				ARSize--;
				ARIndex++;
			} else{
				result.push_back(ALeft[ALIndex]);
				result.push_back(ARight[ARIndex]);
				ALSize--;
				ARSize--;
				ALIndex++;
				ARIndex++;
			}
		
		// else if only the left half has values remaining to be pushed, push them
		} else if (ALSize > 0){
			result.push_back(ALeft[ALIndex]);
			ALIndex++;
			ALSize--;
		
		// else if only the right half has values remaining to be pushed, push them
		} else if (ARSize > 0){
			result.push_back(ARight[ARIndex]);
			ARIndex++;
			ARSize--;
		}
	}
		
	/*
	// For readability
	// downside: each time we erase, we have to copy all items to the right of the 1st element into a new array, resulting in an O(n) operation
	//			 and as a result the merge operation takes O(n^2) instead of O(n)
	while (ALeft.size() > 0 || ARight.size() > 0){
		if (ALeft.size() > 0 && ARight.size() > 0){
			if (ALeft.front() < ARight.front()){
				result.push_back(ALeft.front());
				ALeft.erase(ALeft.begin());
			} else if (ALeft.front() > ARight.front()){
				result.push_back(ARight.front());
				ARight.erase(ARight.begin());
			} else{
				result.push_back(ALeft.front());
				ALeft.erase(ALeft.begin());
				result.push_back(ARight.front());
				ARight.erase(ARight.begin());
			}
		} else if (ALeft.size() > 0){
			result.push_back(ALeft.front());
			ALeft.erase(ALeft.begin());			
		} else if (ARight.size() > 0){
			result.push_back(ARight.front());
			ARight.erase(ARight.begin());
		}
	}
	*/

	// result contains the merged and sorted vector
	return result;

}

/************************************  quick_sort  *************************************/

// worst case:	Theta(n^2)
// best case:	Theta(nlogn)
std::vector<int> Sorting::quick_sort(std::vector<int> A, int left, int right){
	
	// When quicksort is first called, no argument other than A needs to be given. 
	// The index of the rightmost element is assigned to 'right'
	if (right == -100){
		right = A.size()-1;
	}

	// if the subvector to be worked on is of size > 1, recurse further. Otherwise don't do anything
	if (left < right){

		// in the subvector, find at what index the right-most value was placed 
		int pivot = Sorting::partition(A, left, right);

		// recurse on the subvector left of the pivot and on the subvector right of the pivot
		A = Sorting::quick_sort(A, left, pivot-1);
		A = Sorting::quick_sort(A, pivot+1, right); 
	}

	// A is now the sorted subvector
	return A;
}

// worst case:	Theta(n^2) (already sorted or reverse sorted):
// best case:	Theta(nlogn)
// The vector is sorted in place, no extra vectors are needed (saves memory)
void Sorting::quick_sort_in_place(std::vector<int>& A, int left, int right){
	
	// When quicksort is first called, no argument other than A needs to be given. 
	// The index of the rightmost element is assigned to 'right'
	if (right == -100){
		right = A.size()-1;
	}

	// if the subvector to be worked on is of size > 1, recurse further. Otherwise don't do anything
	if (left < right){

		// in the subvector, find at what index the right-most value was placed 
		int pivot = Sorting::partition(A, left, right);

		// recurse on the subvector left of the pivot and on the subvector right of the pivot
		Sorting::quick_sort_in_place(A, left, pivot-1);
		Sorting::quick_sort_in_place(A, pivot+1, right); 
	}
}

// Theta(n)
int Sorting::partition(std::vector<int>& A, int left, int right){
	
	// initialize index to the left-most index 
	int index = left;

	// everything to the left of index is <= to the pivot (right-most element)
	for (int i = left; i < right; i++){
		if (A[i] <= A[right]){
			int temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}

	// swap the pivot with the value at the updated index
	int temp = A[index];
	A[index] = A[right];
	A[right] = temp;

	// this is where A is partitioned
	return index;
}















