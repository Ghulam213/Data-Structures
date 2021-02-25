//
// Created by GM on 15/11/2020.
//

#include "RoundRobinAlgo.h"

RoundRobinAlgo::RoundRobinAlgo() {
    head = nullptr;
}

void RoundRobinAlgo::addProcess(const string& processName, int time) {
    Node *newNode, *nodePtr;

    newNode = new Node;
    newNode->timeLength = time;
    newNode->processName = processName;

    if (head == nullptr){
        head = newNode;
    } else {
        nodePtr = head;
        while(nodePtr->nextNodePtr != head){
            nodePtr = nodePtr->nextNodePtr;
        }
        nodePtr->nextNodePtr = newNode;
    }
    newNode->nextNodePtr = head;

}

void RoundRobinAlgo::displayProcessList(){
    if (!head){
        cout << "No Process to Be Executed\n";
        return;
    }
    cout << "\nProcess being Executed are: \n";
    cout << "[ ";
    Node *nodePtr;
    nodePtr = head;
    while(nodePtr->nextNodePtr != head){
        cout << "{ Process: " << nodePtr->processName << ", ";
        cout << "Time: " << nodePtr->timeLength << " }, ";
        nodePtr = nodePtr->nextNodePtr;
    }
    cout << "{ Process: " << nodePtr->processName << ", ";
    cout << "Time: " << nodePtr->timeLength << " } ]\n";

}

void RoundRobinAlgo::deleteProcess(const string& processName) {
    Node *nodePtr, *previousNode;
    if (head == nullptr){
        return;
    }if (head->processName == processName){
        if (head->nextNodePtr == head){
            delete head;
            head = nullptr;
            return;
        } else {
            previousNode = head;
            while (previousNode->nextNodePtr != head) {
                previousNode = previousNode->nextNodePtr;
            }
            nodePtr = head->nextNodePtr;
            delete head;
            head = nodePtr;
            previousNode->nextNodePtr = head;
        }
    }else{
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->processName != processName){
            previousNode = nodePtr;
            nodePtr = nodePtr->nextNodePtr;
        }
        previousNode->nextNodePtr = nodePtr->nextNodePtr;
        delete nodePtr;
    }
}

void RoundRobinAlgo::process() {
    Node *temp, *currentProcess;
    currentProcess = head;
    while(head){
        cout << "\n[INFO] Processing " << currentProcess->processName << "...\n";
        cout << "[INFO] Time Remaining for " << currentProcess->processName << ": " << currentProcess->timeLength << endl;
        currentProcess->timeLength -= 5;
        if (currentProcess->timeLength <= 0) {
            temp = currentProcess;
            currentProcess = currentProcess->nextNodePtr;
            cout << "\nProcess " << temp->processName << " Finished.\n";
            deleteProcess(temp->processName);
            displayProcessList();
        }else{
            currentProcess = currentProcess->nextNodePtr;
        }
    }
}
