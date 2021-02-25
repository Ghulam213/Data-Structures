//
// Created by GM on 27/11/2020.
//

#ifndef LAB6_QUEUE_H
#define LAB6_QUEUE_H
#include "../Patient/Patient.h"
#include <iostream>

using namespace std;

/*
 * Array based implementation of queue
 */

class Queue {
    private:
        int* queue;
        int front, rear, count, length;
    public:
        Queue(int length);
        void enqueue(int value);
        int dequeue();
        bool isEmpty();
        bool isFull();
        void clear();
        int firstElement();
        int getCount() const;
};


#endif //LAB6_QUEUE_H
