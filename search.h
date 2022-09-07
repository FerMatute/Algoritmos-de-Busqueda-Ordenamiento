#ifndef SEARCH_H
#define SEARCH_H

#include "header.h"
#include <vector>

// =================================================================
// Performs a sequential search for an element within a vector.
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
pair<int, int> sequentialSearch(const std::vector<T> &v, T key) {
	int counter = 0;
	pair<int, int> PAIR1;
	for (int i = 0; i < v.size(); i++) {
		counter++;
		if (v[i] == key) {
			PAIR1.first = counter;
			PAIR1.second = i;
			return PAIR1;
		}
	}
	PAIR1.first = counter;
	PAIR1.second = -1;
	return PAIR1;
}

// =================================================================
// Performs a binary search for an element within a vector
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
pair<int, int> binarySearch(const std::vector<T> &v, T key) {
	int low, high, mid, counter;
	counter = 0;
	pair<int, int> PAIR1;
	low = 0;
	high = v.size() - 1;
	while (low <= high) {
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		counter++;
		if (key == v[mid]) {
			PAIR1.first = counter;
			PAIR1.second = mid;
			return PAIR1;
		} else if (key < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	PAIR1.first = counter;
	PAIR1.second = -1;
	return PAIR1;
}

// =================================================================
// Performs a binary search for an element within a vector
//
// @param A, a vector of T elements.
// @param low, lower limit of the search.
// @param high, upper limit of the search.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int binaryRSearch(const std::vector<T> &v, int low, int high, T key) {
	int mid;

	if (low > high) {
		return -1;
	} else {
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		if (key == v[mid]) {
			return mid;
		} else if (key < v[mid]) {
			return binaryRSearch(v, low, mid - 1, key);
		} else {
			return binaryRSearch(v, mid + 1, high, key);
		}
	}
}

#endif /* SEARCH_H */
