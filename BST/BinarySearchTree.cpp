//
// Created by GM on 11/01/2021.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

bool BinarySearchTree::isEmpty() const {
    return (!root);
}

void BinarySearchTree::print_inorder() {
    inorder(root);
}

void BinarySearchTree::inorder(BinarySearchTree::tree_node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BinarySearchTree::print_preorder() {
    preorder(root);
}

void BinarySearchTree::preorder(BinarySearchTree::tree_node *root) {
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BinarySearchTree::print_postorder() {
    postorder(root);
}

void BinarySearchTree::postorder(BinarySearchTree::tree_node *root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void BinarySearchTree::insert(int data) {
    root = insert(root, data);
}

BinarySearchTree::tree_node* BinarySearchTree::insert(BinarySearchTree::tree_node *root, int data) {
    tree_node* node;
    if (!root) {
        root = new tree_node();
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (root->data > data)
            root->left = insert(root->left, data);
        if (root->data < data)
            root->right = insert(root->right, data);
    }
    return root;
}

void BinarySearchTree::remove(int data) {
    remove(root, data);
}

BinarySearchTree::tree_node* BinarySearchTree::remove(BinarySearchTree::tree_node *root, int data) {
    tree_node* node, *prevNode;
    if (!root)
        return root;
    if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);
    else {                                      // node with req value found
        // 1 child or no child
        if (!root->left) {
            node = root->right;
            delete root;
            return node;
        }
        else if (!root->right) {
            node = root->left;
            delete root;
            return node;
        }
        // 2 child
        else {
            // search for lowest value in right subtree.
            node = root->right;
            while (node->left)
                node = node->left;

            root->data = node->data;
            root->right = remove(root->right, node->data);
        }
    }
    return root;
}
