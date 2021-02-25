//
// Created by GM on 29/12/2020.
//

#include <iostream>
#include "ArrBinaryTree.h"

ArrBinaryTree::ArrBinaryTree() {
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = -1;
}

ArrBinaryTree::ArrBinaryTree(int size) {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = -1;
}

void ArrBinaryTree::insert(int data) {
    insert(0, data);
}

void ArrBinaryTree::insert(int node, int data) {
    if (arr[0] == -1) {
        arr[0] = data;
        return;
    }
    if (arr[node] == -1)
        return;
    if (data < arr[node]) {
        if (arr[getLeftChild(node)] == -1) {
            arr[getLeftChild(node)] = data;
            return;
        } else {
            insert(getLeftChild(node), data);
        }
    } else {
        if (arr[getRightChild(node)] == -1) {
            arr[getRightChild(node)] = data;
            return;
        } else {
            insert(getRightChild(node), data);
        }
    }
}

void ArrBinaryTree::postOrder(int node) {
    if(arr[node] == -1 || node >= size)
        return;
    postOrder(getLeftChild(node));
    postOrder(getRightChild(node));
    std::cout << arr[node] << " ";
}

void ArrBinaryTree::preOrder(int node) {
    if(arr[node] == -1 || node >= size)
        return;
    std::cout << arr[node] << " ";
    preOrder(getLeftChild(node));
    preOrder(getRightChild(node));
}

void ArrBinaryTree::inOrder(int node) {
    if(arr[node] == -1 || node >= size)
        return;
    inOrder(getLeftChild(node));
    std::cout << arr[node] << " ";
    inOrder(getRightChild(node));
}

int ArrBinaryTree::getRightChild(int node) {
    return (2 * node) + 2;
}

int ArrBinaryTree::getLeftChild(int node) {
    return (2 * node) + 1;
}
