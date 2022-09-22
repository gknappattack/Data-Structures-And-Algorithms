//
// Created by Gregory Knapp on 5/14/20.
//

#include "QS.h"

void QS::sortAll() {
    quicksort(0, arraySize - 1);
}

int QS::medianOfThree(int left, int right) {

    if (left >= right) {
        return -1;
    }
    if (left < 0 || right > arraySize - 1) {
        return -1;
    }
    if (arraySize == 0) {
        return -1;
    }

    int middle = (left + right) / 2;

    if (table[left] > table[middle]) {
        int temp = table[left];
        table[left] = table[middle];
        table[middle] = temp;
    }
    if (table[right] < table[middle]) {
        int temp = table[right];
        table[right] = table[middle];
        table[middle] = temp;
    }
    if (table[middle] < table[left]) {
        int temp = table[left];
        table[left] = table[middle];
        table[middle] = temp;
    }
    return middle;
}

int QS::partition(int left, int right, int pivotIndex) {

    if (table == nullptr) {
        return -1;
    }
    if (left < 0 || right > arraySize - 1) {
        return -1;
    }
    if (left >= right) {
        return -1;
    }
    if (pivotIndex < left || pivotIndex > right) {
        return -1;
    }


    int temp = table[pivotIndex];
    table[pivotIndex] = table[left];
    table[left] = temp;

    int up = left + 1;
    int down = right;

    do {
        while ((table[up] <= table[left]) && (up < right)) {
            up++;
        }
        while ((table[down] > table[left]) && down > left) {
            down--;
        }
        if (up < down) {
            temp = table[up];
            table[up] = table[down];
            table[down] = temp;
        }
    } while (up < down);

    temp = table[left];
    table[left] = table[down];
    table[down] = temp;

    return down;
}

string QS::getArray() const {
    string myArray;
    cout << "printing current array" << endl;


    for (int i = 0; i < arraySize; i++) {
        if (i == arraySize - 1) {
            myArray += to_string(table[i]);
        }
        else {
            myArray += to_string(table[i]) + ",";
        }
    }

    return myArray;
}

int QS::getSize() const {
    return arraySize;
}

bool QS::addToArray(int value) {

    if (arraySize == arrayCapacity) {
        cout << "array is full!" << endl;
        return false;
    }

    table[arraySize] = value;
    arraySize += 1;

    cout << "successfully added number " << value << endl;
    cout << "current size of array: " << arraySize << endl;
    return true;
}

bool QS::createArray(int capacity) {

    if (table != nullptr) {
        this->clear();
    }

    if (capacity <= 0) {
        cout << "enter a size bigger than 0" << endl;
        return false;
    }
    table = new int[capacity];
    for (int i = 0; i < capacity - 1; i++) {
        table[i] = 0;
    }
    arrayCapacity = capacity;

    cout << "array successfully created" << endl;
    return true;
}

void QS::clear() {
    if (table != nullptr) {
        delete [] table;
        table = nullptr;
        cout << "old array was deleted!" << endl;
    }
    arraySize = 0;

}
void QS::quicksort(int first, int last) {

    if ((last - first) < 1) {
        return;
    }

    int pivot = medianOfThree(first, last);
    pivot = partition(first, last, pivot);
    quicksort(first, pivot - 1);
    quicksort(pivot + 1, last);
}