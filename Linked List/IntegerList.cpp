//
// Created by GM on 22/10/2020.
//

#include "IntegerList.h"
#include <iostream>

using namespace std;

IntegerList::IntegerList() {
    head = nullptr;
}

IntegerList::~IntegerList() = default;

void IntegerList::insertAtHead(int num) {
    Node *newNode, *nodePtr;

    newNode = new Node;
    newNode->value = num;
    newNode->nextNodePtr = nullptr;

    if (head == nullptr){
        head = newNode;
    } else {
        newNode->nextNodePtr = head;
        head = newNode;
    }
}

void IntegerList::insertAtLocation(int loc, int num) {
    if (!head) {
        if (loc == 0)
            insertAtHead(num);
        else
            cout << "Insertion not Possible at location " << loc << ". Try adding at 0 first." << endl;
    } else {
        Node *newNode, *nodePtr, *previousPtr;
        newNode = new Node;
        newNode->value = num;
        nodePtr = head;
        for (int i = 0; i < loc; i++){
            if (!nodePtr->nextNodePtr){
                cout << "Insertion not Possible at location " << loc << ". Not enough nodes." << endl;
                return;
            }
            previousPtr = nodePtr;
            nodePtr = nodePtr->nextNodePtr;
        }
        previousPtr->nextNodePtr = newNode;
        newNode->nextNodePtr = nodePtr;
    }
}

void IntegerList::displayList() {
    cout << "[ ";
    Node *nodePtr;
    nodePtr = head;
    while(nodePtr->nextNodePtr){
        cout << nodePtr->value << ", ";
        nodePtr = nodePtr->nextNodePtr;
    }
    cout << nodePtr->value << " ] \n";

}

void IntegerList::deleteNode(int num) {
    Node *nodePtr, *previousNode;
    if (head == nullptr){
        cout << "Deletion not Possible. Try adding at 0 first." << endl;
        return;
    }if (head->value == num){
        nodePtr = head->nextNodePtr;
        delete head;
        head = nodePtr;
    }else{
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->value != num){
            previousNode = nodePtr;
            nodePtr = nodePtr->nextNodePtr;
        }
        previousNode->nextNodePtr = nodePtr->nextNodePtr;
        cout << "The deleted no is: " << nodePtr->value << endl;
        delete nodePtr;
    }

}

void IntegerList::deleteAtHead(){
    Node *nodePtr, *previousNode;
    if (head == nullptr){
        cout << "Deletion not Possible. Try adding at 0 first." << endl;
        return;
    }else {
        nodePtr = head->nextNodePtr;
        delete head;
        head = nodePtr;
    }
}

void IntegerList::countList() {
    int count = 0;
    Node *nodePtr;
    if (!head){
        cout << "The length of list is: " << count << endl;
        return;
    }
    nodePtr = head;
    while (nodePtr->nextNodePtr){
        nodePtr = nodePtr->nextNodePtr;
        count++;
    }
    cout << "The length of list is: " << count + 1 << endl;
    return;
}

