//
// Created by GM on 03/12/2020.
//

#include "SortingAlgorithms.h"


void SortingAlgorithms::swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
}


void SortingAlgorithms::displayArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << ", ";
    cout << endl;
}

void SortingAlgorithms::bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-i-1; j++){
            if (array[j] > array[j+1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void SortingAlgorithms::selectionSort(int *array, int size) {
    int index;
    for (int i = 0; i < size; i++){
        index = i;
        for (int j = i; j < size; j++){
            if (array[j] < array[index])
                index = j;
        }
        swap(&array[i], &array[index]);
    }
}

void SortingAlgorithms::insertionSort(int *array, int size) {
    int temp , j;
    for (int i = 1; i < size; i++){
        temp = array[i];
        for (j = i; j > 0; j--){
            if (temp < array[j - 1])
                array[j] = array[j - 1];
            else
                break;
        }
        array[j] = temp;
    }
}

int SortingAlgorithms::quickSortPartition(int *array, int low, int high) {
    int piv = array[low];
    int i = high + 1;

    for (int j = high; j >= low + 1; j--){
        if (array[j] > piv){
            i--;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i - 1], &array[low]);
    return i - 1;
}

void SortingAlgorithms::quickSort(int *array, int low, int high) {
    if (low >= high)
        return;
    int pi = quickSortPartition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
}

void SortingAlgorithms::countingSort(int *array, int size) {
    int largest = array[0];
    int* temp = new int[size];
    int t, j = 0;

    for (int i = 0; i < size; i++)
        if (largest < array[i])
            largest = array[i];

    int freq[largest + 1];

    for (int i = 0; i <= largest; i++)
        freq[i] = 0;

    for (int i = 0; i < size; i++)
        freq[array[i]]++;

    for (int i = 0; i <= largest; i++){
        t = freq[i];
        while(t--)
            temp[j++] = i;
    }

    for (int i = 0; i < size; i++)
        array[i] = temp[i];
}

void SortingAlgorithms::radixSort(int *array, int size) {
    queue<int> queue[10];
    for (int d = 0, factor = 1; d < 10; factor *= 10, d++){
        for (int j = 0; j < size; j++)
            queue[(array[j]/factor) % 10].push(array[j]);
        for (int j = 0, k = 0; j < 10; j++){
            while (!queue[j].empty()) {
                array[k++] = queue[j].front();
                queue[j].pop();
            }
        }
    }
}


