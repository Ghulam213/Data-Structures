//
// Created by GM on 20/01/2021.
//

#ifndef LAB12_MINHEAP_H
#define LAB12_MINHEAP_H


class MinHeap {
    private:
        int* heapArr;
        int capacity;
        int size;
        int parent(int i);
        int leftChild(int i);
        int rightChild(int i);
    public:
        MinHeap();
        MinHeap(int capacity);
        void minHeapify(int index);
        void minHeapifyUtil(int arr[], int index, int size);
        int top();
        int pop();
        void push(int num);
        bool isEmpty();
        int getSize();
        int getHeight();
        void buildHeap(int arr[], int size);
        void print();

};


#endif //LAB12_MINHEAP_H
