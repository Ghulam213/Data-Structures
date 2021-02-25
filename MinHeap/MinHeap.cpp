//
// Created by GM on 20/01/2021.
//

#include <cmath>
#include <iostream>
#include <algorithm>
#include "MinHeap.h"

int MinHeap::parent(int i) {
    return (i - 1) / 2;
}

int MinHeap::leftChild(int i) {
    return (2 *i) + 1;
}

int MinHeap::rightChild(int i) {
    return (2 * i) + 2;
}

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    size = 0;
    heapArr = new int[capacity];
}

MinHeap::MinHeap(){
    capacity = 100;
    size = 0;
    heapArr = new int[capacity];
}

void MinHeap::minHeapify(int index) {
    minHeapifyUtil(heapArr, index, size);
}

void MinHeap::minHeapifyUtil(int *arr, int index, int size) {
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest = index;

    if (left < size && arr[left] < arr[index])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != index){
        std::swap(arr[index], arr[smallest]);
        minHeapifyUtil(arr, smallest, size);
    }
}

int MinHeap::top() {
    if (size >= 0)
        return heapArr[0];
    return INT_MAX;
}

int MinHeap::pop() {
    if (size <= 0)
        return INT_MAX;
    if (size == 1){
        return heapArr[--size];
    }
    int root = heapArr[0];
    heapArr[0] = heapArr[--size];
    minHeapify(0);
    return root;
}

void MinHeap::push(int num) {
    if (size >= capacity)
        return;
    heapArr[size++] = num;
    int index = size - 1;
    while (index != 0 && heapArr[parent(index)] > heapArr[index]){
        std::swap(heapArr[parent(index)], heapArr[index]);
        index = parent(index);
    }
}

bool MinHeap::isEmpty() {
    return size == 0;
}

int MinHeap::getSize() {
    return size;
}

int MinHeap::getHeight() {
    return floor(log2(size)) + 1;
}

void MinHeap::buildHeap(int *arr, int ArrSize) {
    for (int i = (ArrSize/2) - 1; i >= 0; i--)
        minHeapifyUtil(arr, i, ArrSize);
}

void MinHeap::print() {
    std::cout << "Array representation of Heap is:\n";

    for (int i = 0; i < size; ++i)
        std::cout << heapArr[i] << " ";
    std::cout << "\n";
}


