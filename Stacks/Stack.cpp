//
// Created by GM on 06/11/2020.
//

#include "Stack.h"

Stack::Stack(int length) : length(length) {
    items = new int [length];
    top = -1;
}

bool Stack::isFull() {
    return top == length - 1;
}

bool Stack::isEmpty() {
    return top < 0;
}

void Stack::push(int no) {
    if (!isFull()){
        items[++top] = no;
    }
}

int Stack::pop() {
    int element = -1;
    if (!isEmpty()){
        element = items[top];
        items[top--] = -1;
    }
    return element;
}

std::string Stack::displayStack() {
    std::string str = "";
    for (int i = top; i > -1; i--)
        str += "|" + std::to_string(items[i]) + "|\n" ;
    str += "_______";
    return str;
}

int Stack::getLength() const {
    return length;
}

int Stack::elementCount() {
    return top + 1;
}
