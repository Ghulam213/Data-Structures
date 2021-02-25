//
// Created by GM on 02/02/2021.
//

#ifndef ASSIGNMENT3_AVL_H
#define ASSIGNMENT3_AVL_H
#include <string>
#include <iostream>

using namespace std;

class AVL {
    private:
        struct Node {
            string data;
            Node* left;
            Node* right;
            int height;
        };

        Node* head;
        Node* getNewNode(Node* node, string data);
        int count = 0;

    public:
        AVL();
        int getBalance(Node* node);
        int getHeight(Node* node);
        Node* rightRotate(Node* node);
        Node* leftRotate(Node* node);
        int insert(string data);
        Node* insert(Node* head, string data);
        int remove(string data);
        Node* remove(Node* head, string data);
        void preOrder();
        void preOrder(Node* head);
        void postOrder();
        void postOrder(Node* head);
        void inOrder();
        void inOrder(Node* head);

    int getCount() const;
};


#endif //ASSIGNMENT3_AVL_H
