//
// Created by GM on 03/02/2021.
//

#ifndef ASSIGNMENT3_AVLHASHTABLE_H
#define ASSIGNMENT3_AVLHASHTABLE_H

#include <tuple>

#include "../AVL/AVL.h"

class AVLHashTable {
    private:
        AVL* hashArr[8];
        unsigned int hash(string data);
        int count;
        int loadFactor;

    public:
        AVLHashTable();
        AVLHashTable(string pathToFile);
        void populate(string pathToFile);
        std::tuple<int, int> insert(string data);
        std::tuple<int, int> remove(string data);
        void preOrder();
        void postOrder();
        void inOrder();

};


#endif //ASSIGNMENT3_AVLHASHTABLE_H
