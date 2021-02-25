//
// Created by GM on 23/12/2020.
//

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
    head = nullptr;
}

void LinkedQueue::enqueue(int value) {
    /*
     * Linked List logic of insert at last node.
     */
    Node *newNode, *nodePtr;

    newNode = new Node;
    newNode->value = value;
    newNode->nextNodePtr = nullptr;

    if (head == nullptr){
        head = newNode;
    } else {
        nodePtr = head;
        while (nodePtr->nextNodePtr)
            nodePtr = nodePtr->nextNodePtr;
        nodePtr->nextNodePtr = newNode;
    }
}

int LinkedQueue::dequeue() {
    /*
     * Linked List logic of delete at head.
     */
    Node *nodePtr;
    int value = 0;
    if (head == nullptr){
        cout << "Deletion not Possible. Try adding at 0 first." << endl;
    }else {
        nodePtr = head->nextNodePtr;
        value = head->value;
        delete head;
        head = nodePtr;
    }
    return value;
}

bool LinkedQueue::isEmpty() {
    return head == nullptr;
}

void LinkedQueue::clear() {
    int count = getCount();
    for (int i = 0; i < count; i++)
        dequeue();
}

int LinkedQueue::firstElement() {
    return head->value;
}

int LinkedQueue::getCount() {
    /*
     * Linked List logic of count.
     */
    int count = 0;
    if (!head)
        cout << "The length of list is: " << count << endl;
    else {
        Node *nodePtr;
        nodePtr = head;
        while (nodePtr->nextNodePtr) {
            nodePtr = nodePtr->nextNodePtr;
            count++;
        }
    }
    return count + 1;
}

void LinkedQueue::displayList() {
    /*
     * Linked List logic of display.
     */
    if (!head)
        return;
    cout << "[ ";
    Node *nodePtr;
    nodePtr = head;
    while(nodePtr->nextNodePtr){
        cout << nodePtr->value << ", ";
        nodePtr = nodePtr->nextNodePtr;
    }
    cout << nodePtr->value << " ] \n";
}
