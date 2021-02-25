//
// Created by GM on 03/12/2020.
//

#ifndef INC_1STPROJECT_SORTINGALGORITHMS_H
#define INC_1STPROJECT_SORTINGALGORITHMS_H

#include <iostream>
#include <queue>

using namespace std;

class SortingAlgorithms {
    private:
        void swap(int *x, int *y);
        int quickSortPartition(int array[], int low, int high);
    public:
        void displayArray(int array[], int size);
        void bubbleSort(int array[], int size);
        void selectionSort(int array[], int size);
        void insertionSort(int array[], int size);
        void quickSort(int array[], int low, int high);
        void countingSort(int array[], int size);
        void radixSort(int array[], int size);
};


#endif //INC_1STPROJECT_SORTINGALGORITHMS_H
