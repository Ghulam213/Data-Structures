//
// Created by GM on 15/11/2020.
//

#ifndef ASSIGNMENT_1_ROUNDROBINALGO_H
#define ASSIGNMENT_1_ROUNDROBINALGO_H

#include <string>
#include <iostream>

using namespace std;

/*
 *  This algorithm is implemented using circular Linked List.
 */

class RoundRobinAlgo {
    private:
        struct Node{
            string processName;
            int timeLength;
            struct Node* nextNodePtr;
        };
        Node* head;

    public:
        RoundRobinAlgo();
        void addProcess(const string& processName, int time);
        void displayProcessList();
        void deleteProcess(const string& processName);
        void process();

};


#endif //ASSIGNMENT_1_ROUNDROBINALGO_H
