//
// Created by Gregory Knapp on 5/14/20.
//

#ifndef QS_H_
#define QS_H_

#include <iostream>
#include <string>
#include <sstream>
#include "QSInterface.h"
using namespace std;

/*
* WARNING: You may not modify any part of this document, including its name
*/

class QS : public QSInterface
{
public:
    QS() {
        table = nullptr;
        arraySize = 0;
        arrayCapacity = 0;
    }
    ~QS() {}

    /*
    * sortAll()
    *
    * Sorts elements of the array.  After this function is called, every
    * element in the array is less than or equal its successor.
    *
    * Does nothing if the array is empty.
    */
    void sortAll();
    int medianOfThree(int left, int right);

    /*
    * Partitions a subarray around a pivot value selected according to
    * median-of-three pivot selection.  Because there are multiple ways to partition a list,
    * we will follow the algorithm on page 611 of the course text when testing this function.
    *
    * The values which are smaller than the pivot should be placed to the left
    * of the pivot; the values which are larger than the pivot should be placed
    * to the right of the pivot.
    *
    * Returns -1 if the array is null, if either of the given integers is out of
    * bounds, or if the first integer is not less than the second integer, or if the
    * pivot is not within the sub-array designated by left and right.
    *
    * @param left
    * 		the left boundary for the subarray to partition
    * @param right
    * 		the right boundary for the subarray to partition
    * @param pivotIndex
    * 		the index of the pivot in the subarray
    * @return
    *		the pivot's ending index after the partition completes; -1 if
    * 		provided with bad input
    */
    int partition(int left, int right, int pivotIndex);
    string getArray() const;
    int getSize() const;

    /*
    * Adds the given value to the end of the array starting at index 0.
    * For example, the first time addToArray is called,
    * the give value should be found at index 0.
    * 2nd time, value should be found at index 1.
    * 3rd, index 2, etc up to its max capacity.
    *
    * If the array is filled, do nothing.
    * returns true if a value was added, false otherwise.
    */
    bool addToArray(int value);

    /*
    * Dynamically allocates an array with the given capacity.
    * If a previous array had been allocated, delete the previous array.
    * Returns false if the given capacity is non-positive, true otherwise.
    *
    * @param
    *		size of array
    * @return
    *		true if the array was created, false otherwise
    */
    bool createArray(int capacity);

    /*
    * Resets the array to an empty or NULL state.
    */
    void clear();
    void quicksort(int first, int last);

private:
    int* table;
    int arrayCapacity;
    int arraySize;
};

#endif /* QS_H_ */

