//
// Created by GM on 02/02/2021.
//

#include "AVL.h"

AVL::AVL() {
    head = nullptr;
}

int AVL::getBalance(AVL::Node *node) {
    if (!node)
        return 0;
    return getHeight(node->right) - getHeight(node->left);
}

int AVL::getHeight(AVL::Node *node) {
    if (!node)
        return 0;
    return node->height;
}

AVL::Node *AVL::getNewNode(AVL::Node *node, string data) {
    node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

AVL::Node* AVL::rightRotate(AVL::Node *node) {
    Node* leftChild = node->left;
    Node* leftRightChild = leftChild->right;

    leftChild->right = node;
    node->left = leftRightChild;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return leftChild;
}

AVL::Node* AVL::leftRotate(AVL::Node *node) {
    Node* rightChild = node->right;
    Node* rightLeftChild = rightChild->left;

    rightChild->left = node;
    node->right = rightLeftChild;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    return rightChild;
}

int AVL::remove(string data) {
    head = remove(head, data);
    return head->height;
}

AVL::Node* AVL::remove(AVL::Node *head, string data) {
    Node* node, *prevNode;
    if (!head)
        return head;
    if (data < head->data)
        head->left = remove(head->left, data);
    else if (data > head->data)
        head->right = remove(head->right, data);
    else {                                      // node with req value found
        // 1 child or no child
        if (!head->left) {
            node = head->right;
            delete head;
            count--;
            return node;
        }
        else if (!head->right) {
            node = head->left;
            delete head;
            count--;
            return node;
        }
            // 2 child
        else {
            // search for lowest value in right subtree.
            node = head->right;
            while (node->left)
                node = node->left;

            head->data = node->data;
            head->right = remove(head->right, node->data);
        }
    }

    head->height = max(getHeight(head->left), getHeight(head->right)) + 1;

    if (!head)
        return head;

    int balance = getBalance(head);

    // left left case
    if (balance < -1 && getBalance(head->left) > 0)
        return rightRotate(head);
    // left right case
    if (balance < -1 && getBalance(head->left) <= 0) {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }
    // right right case
    if (balance > 1 && getBalance(head->right) > 0)
        return leftRotate(head);
    // right left case
    if (balance > 1 && getBalance(head->right) <= 0) {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }
    return head;
}

int AVL::insert(string data) {
    head = insert(head, data);
    return head->height;
}

AVL::Node* AVL::insert(AVL::Node *head, string data) {
    if (!head) {
        Node* newNode;
        count++;
        return getNewNode(newNode, data);
    }

    if (head->data < data) {
        head->right = insert(head->right, data);
    }
    else if (head->data > data) {
        head->left = insert(head->left, data);
    }
    else {
        return head;
    }

    head->height = max(getHeight(head->left), getHeight(head->right)) + 1;
    int balance = getBalance(head);

    // left left case
    if (balance < -1 && data < head->left->data)
        return rightRotate(head);
    // left right case
    if (balance < -1 && data > head->left->data) {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }
    // right right case
    if (balance > 1 && data > head->right->data)
        return leftRotate(head);
    // right left case
    if (balance > 1 && data < head->right->data) {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }

    return head;
}

void AVL::preOrder() {
    preOrder(head);
}

void AVL::preOrder(AVL::Node *head) {
    if(head) {
        cout << head->data << ", ";
        preOrder(head->left);
        preOrder(head->right);
    }
}

void AVL::postOrder() {
    postOrder(head);
}

void AVL::postOrder(AVL::Node *head) {
    if(head) {
        preOrder(head->left);
        preOrder(head->right);
        cout << head->data << ", ";
    }
}

void AVL::inOrder() {
    inOrder(head);
}

void AVL::inOrder(AVL::Node *head) {
    if(head) {
        preOrder(head->left);
        cout << head->data << ", ";
        preOrder(head->right);
    }
}

int AVL::getCount() const {
    return count;
}
