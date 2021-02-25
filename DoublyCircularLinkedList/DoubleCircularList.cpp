//
// Created by GM on 13/11/2020.
//

#include "DoubleCircularList.h"

#include<iostream>
using namespace std;


DoubleCircularList::DoubleCircularList() {
    start = nullptr;
    last = nullptr;
}

DoubleCircularList::node *DoubleCircularList::createNode(int value) {
    struct node *temp;
    temp = new node;
    temp->info = value;
    return temp;
}

/*
 *INSERTS ELEMENT AT BEGINNING
 */

void DoubleCircularList::insertAtStart() {
    int value;
    cout<<endl<<"Enter the element to be inserted at Start of the List:";
    cin>>value;

    node *newNode = createNode(value);

    if (start){
        newNode->next = start;
        newNode->prev = last;
        start->prev = newNode;
        start = newNode;
        last->next = start;
    } else {
        newNode->next = newNode;
        newNode->prev = newNode;
        start = newNode;
        last = newNode;
    }
    counter++;
    cout << "[INFO] Value added at Start of list." << endl;
}

/*
 *INSERTS ELEMENT AT LAST
 */

void DoubleCircularList::insertAtLast() {
    int value;
    cout<<endl<<"Enter the element to be inserted at Last of the List:";
    cin>>value;

    node *newNode = createNode(value);
    if (last){
        newNode->prev = last;
        newNode->next = start;
        last->next = newNode;
        last = newNode;
    } else {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        last = newNode;
        start = newNode;
    }
    counter++;
    cout << "[INFO] Value added at Last of the list." << endl;
}

/*
 *INSERTS ELEMENT AT POSITION
 */

void DoubleCircularList::insertAtPos() {
    int value, pos, i;
    cout << endl << "Enter the element to be inserted at a position:";
    cin >> value;
    cout << endl << "Enter the position of element to be inserted:";
    cin >> pos;

    if (pos == 0)
        insertAtStart();
    else if (!start)
        cout << "Insertion not Possible at location " << pos << ". Try adding at 0 first." << endl;
    else {
        node *newNode, *nodePtr, *previousPtr;
        newNode = createNode(value);
        nodePtr = start;
        for (int i = 0; i < pos; i++) {
            if (nodePtr->next == start) {
                cout << "Insertion not Possible at location " << pos << ". Not enough nodes." << endl;
                return;
            }
            previousPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousPtr->next = newNode;
        newNode->next = nodePtr;
        newNode->prev = previousPtr;
        nodePtr->prev = newNode;

        counter++;
        cout << "[INFO] Value Inserted at Position " << pos << endl;
    }
}

/*
 * Delete Node at Particular Position
 */

void DoubleCircularList::deleteAtPos() {
    int pos, i;
    node *previousPtr, *nodePtr;
    if (start == last && start == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }
    cout << endl << "Enter the position of element to be deleted:";
    cin >> pos;

    nodePtr = start;
    if (pos == 0) {
        previousPtr = last;
        previousPtr->next = nodePtr->next;
        nodePtr->next->prev = previousPtr;
        start = nodePtr->next;
    } else {
        for (i = 0; i < pos; i++) {
            if (nodePtr->next == start) {
                cout << "Deletion not Possible at location " << pos << ". Not enough nodes." << endl;
                return;
            }
            previousPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousPtr->next = nodePtr->next;
        nodePtr->next->prev = previousPtr;
    }
    delete nodePtr;
    cout << "[INFO] Value Deleted at Position " << pos << endl;
}

/*
 * Display Elements of the List
 */

void DoubleCircularList::display() {
    cout << endl << "[ ";
    node *nodePtr;
    nodePtr = start;
    while(nodePtr->next != start){
        cout << nodePtr->info << ", ";
        nodePtr = nodePtr->next;
    }
    cout << nodePtr->info << " ] \n";
}