//
// Created by GM on 06/11/2020.
//

#ifndef INC_1STPROJECT_STACK_H
#define INC_1STPROJECT_STACK_H


#include <ostream>

class Stack {
    public:
        int length;
        Stack(int length);
        bool isFull();
        bool isEmpty();
        void push(int no);
        int pop();
        std::string displayStack();
        int elementCount();
        int getLength() const;

private:
        int *items;
        int top;
};


#endif //INC_1STPROJECT_STACK_H
