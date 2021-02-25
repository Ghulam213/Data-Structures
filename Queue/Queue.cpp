//
// Created by GM on 27/11/2020.
//

#include "Queue.h"

Queue::Queue(int length) {
    this->length = length;
    queue = new int[length];
    front = 0;
    rear = 0;
    count = 0;
}

void Queue::enqueue(int value) {
    if (isFull())
        cout << "The Queue is Full, Please Wait.\n";
    else {
        queue[rear++] = value;
        count++;
    }
}

bool Queue::isEmpty() {
    return count == 0;
}

bool Queue::isFull() {
    return count == 99;
    // maximum length  available is 100
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "The Queue is Empty, Please Add data first.\n";
        return 0;
    }
    int value = queue[front];
    queue[front++] = 0;
    count--;
    return value;
}

void Queue::clear() {
    for (int i = 0; i < rear; i++)
        queue[i] = 0;
    front = 0, rear = 0, count = 0;
}

int Queue::firstElement() {
    return queue[front];

}

int Queue::getCount() const {
    return count;
}
