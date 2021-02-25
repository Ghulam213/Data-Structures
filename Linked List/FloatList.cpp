//
// Created by GM on 22/10/2020.
//

#include "FloatList.h"
#include <iostream>

using namespace std;

FloatList::FloatList() {
    head = nullptr;
}

FloatList::~FloatList() {}

void FloatList::appendNode(float num) {
    Node *newNode, *nodePtr;

    newNode = new Node;
    newNode->value = num;
    newNode->nextNodePtr = nullptr;

    if (head == nullptr){
        head = newNode;
    } else {
        nodePtr = head;
        while(nodePtr->nextNodePtr){
            nodePtr = nodePtr->nextNodePtr;
        }
        nodePtr->nextNodePtr = newNode;
    }

}

void FloatList::displayList() {
    cout << "[ ";
    Node *nodePtr;
    nodePtr = head;
    while(nodePtr->nextNodePtr){
        cout << nodePtr->value << ", ";
        nodePtr = nodePtr->nextNodePtr;
    }
    cout << nodePtr->value << " ] \n";

}

void FloatList::deleteNode(float num) {
    Node *nodePtr, *previousNode;
    if (head == nullptr){
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
        delete nodePtr;
    }

}

FloatList::Node *FloatList::reverse() {
    Node *tmpPtr, *newHead;
    newHead = nullptr;
    tmpPtr = nullptr;

    while(head){
        tmpPtr = head->nextNodePtr;
        head->nextNodePtr = newHead;
        newHead = head;
        head = tmpPtr;
    }
    head = newHead;
    return newHead;
}

FloatList::Node *FloatList::getHead() const {
    return head;
}

void FloatList::setHead(FloatList::Node *head) {
    FloatList::head = head;
}
