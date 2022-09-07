
#ifndef INSERTION_H
#define INSERTION_H

#include "header.h"
#include <vector>

// =================================================================
// Performs the insertion sort algorith on a vector.
//
// @param A, a vector of T elements.
// =================================================================
template <class T>
int insertionSort(std::vector<T> &v) {
	int counter = 0;
	for(int i = 1; i < v.size(); i++){
		for(int j = i; j > 0 && v[j] < v[j - 1]; j--){
			counter++;
			swap(v, j, j - 1);
		}
	}
	return counter;
}

#endif /* INSERTION_H */
