//
// Created by GM on 11/01/2021.
//

#ifndef LAB11_BINARYSEARCHTREE_H
#define LAB11_BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

class BinarySearchTree {
    private:
        struct tree_node{
            tree_node* left;
            tree_node* right;
            int data;
        };
        tree_node* root;
    public:
        BinarySearchTree();
        bool isEmpty() const;
        void print_inorder();
        void inorder(tree_node* root);
        void print_preorder();
        void preorder(tree_node* root);
        void print_postorder();
        void postorder(tree_node* root);
        void insert(int data);
        tree_node* insert(tree_node* root, int data);
        void remove(int data);
        tree_node* remove(tree_node* root, int data);
};


#endif //LAB11_BINARYSEARCHTREE_H
