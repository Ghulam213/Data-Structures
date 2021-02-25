//
// Created by GM on 13/11/2020.
//

#ifndef LAB4_DOUBLECIRCULARLIST_H
#define LAB4_DOUBLECIRCULARLIST_H


#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*
 * Class Declaration
 */
class DoubleCircularList
{
public:
    int counter = 0;

    struct node{
        int info;
        struct node *next;
        struct node *prev;
    };
    node *start{}, *last{};

    DoubleCircularList();
    node* createNode(int value);
    void insertAtStart();
    void insertAtLast();
    void insertAtPos();
    void deleteAtPos();
    void display();
};

#endif //LAB4_DOUBLECIRCULARLIST_H
