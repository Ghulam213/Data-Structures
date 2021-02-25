//
// Created by GM on 20/11/2020.
//

#include "CharStack.h"


void CharStack::push(char c) {
    if(isFull())
            cout<<"Stack is full!"<<endl;
    else
        stack[++top]=c;
}

char CharStack::pop() {
    if(isEmpty())
        cout<<"Stack is empty !"<<endl;
    else
        return stack[top--];
}

char CharStack::Peek() {
    if(isEmpty())
        cout<<"Stack is empty !"<<endl;
    else
        return stack[top];
}

bool CharStack::isFull() {
    return top >= length - 1;
}

bool CharStack::isEmpty() {
    return top <= -1;
}

void CharStack::display() {
    if(!isEmpty()){
        cout<<"[ ";
        for(int i=0;i<=top;i++)
            cout<<stack[i]<< ", ";
        cout<<"]\n";
    }
    else
        cout<<" Stack is empty! "<<endl;
}

void CharStack::clear() {
    for (int i = 0; i <= top; i++)
        stack[i] = 0;
    top = -1;
}
