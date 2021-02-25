//
// Created by GM on 20/11/2020.
//

#ifndef LAB5_CHARSTACK_H
#define LAB5_CHARSTACK_H

#include <iostream>
using namespace std;


class CharStack {
    private:
        char stack[100];
        int length = 100;
        int top= -1;

    public:
        void push(char c);
        char pop();
        char Peek();
        bool isFull();
        bool isEmpty();
        void display();
        void clear();
};


#endif //LAB5_CHARSTACK_H
