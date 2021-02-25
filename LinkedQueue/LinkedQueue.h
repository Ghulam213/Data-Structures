//
// Created by GM on 23/12/2020.
//

#ifndef INC_1STPROJECT_LINKEDQUEUE_H
#define INC_1STPROJECT_LINKEDQUEUE_H

#include <iostream>

using namespace std;

/*
 * Linked List based implementation of queue.
 * One can just import pre made linked list and use it's required functions
 * e.g insertAtHead function of linked list can be used for enqueue.
 * I am going to implement it from scratch.
 */

class LinkedQueue {
    private:
        struct Node{
            int value;
            struct Node* nextNodePtr;
        };
        Node* head;
    public:
        LinkedQueue();
        void enqueue(int value);
        int dequeue();
        bool isEmpty();
        void clear();
        int firstElement();
        int getCount();
        void displayList();

};


#endif //INC_1STPROJECT_LINKEDQUEUE_H
