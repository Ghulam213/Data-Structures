//
// Created by GM on 29/12/2020.
//

#ifndef INC_1STPROJECT_ARRBINARYTREE_H
#define INC_1STPROJECT_ARRBINARYTREE_H

/*
 * This implementation utilizes arrays as underlying data structures.
 */

class ArrBinaryTree {
    private:
        int* arr;
        int size = 128;
    public:
        ArrBinaryTree();
        explicit ArrBinaryTree(int size);
        void insert(int data);
        void insert(int node, int data);
        void inOrder(int node);
        void postOrder(int node);
        void preOrder(int node);
        int getRightChild(int node);
        int getLeftChild(int node);
};


#endif //INC_1STPROJECT_ARRBINARYTREE_H
