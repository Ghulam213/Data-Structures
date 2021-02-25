//
// Created by GM on 03/02/2021.
//

#include "AVLHashTable.h"
#include <algorithm>
#include <fstream>

void AVLHashTable::populate(string pathToFile) {
    string line;
    ifstream dict_file(pathToFile);

    while (getline(dict_file, line)) {
        insert(line);
    }

    dict_file.close();
}

unsigned int AVLHashTable::hash(string data) {
    return data[0] & 7;
}

AVLHashTable::AVLHashTable() {
    AVLHashTable("");
}

AVLHashTable::AVLHashTable(string pathToFile) {
    for (int i = 0; i < 8 ; i++)
        hashArr[i] = new AVL();
    count = 0;
    loadFactor = 12;
    if (pathToFile != "")
        populate(pathToFile);
}

std::tuple<int, int> AVLHashTable::insert(string data) {
    int hashValue = hash(data);
    int height;
    while (true) {
        if (hashArr[hashValue]->getCount() < loadFactor) {
            height = hashArr[hashValue]->insert(data);
            count++;
            break;
        }
        hashValue == 7 ? hashValue = 0: hashValue++ ;
    }
    return std::make_tuple(hashValue, height);
}

std::tuple<int, int> AVLHashTable::remove(string data) {
    int hashValue = hash(data);
    int height, prevCount;
    while (true) {
        prevCount = hashArr[hashValue]->getCount();
        height = hashArr[hashValue]->remove(data);
        if (prevCount - hashArr[hashValue]->getCount() == 1) {
            count--;
            break;
        }
        hashValue == 7 ? hashValue = 0: hashValue++ ;
    }
    return std::make_tuple(hashValue, height);
}

void AVLHashTable::postOrder() {
    for (int i = 0; i < 8; i++) {
        cout << "HashTable[ " << i << " ]===> {";
        hashArr[i]->postOrder();
        cout << "}\n\n";
    }
}

void AVLHashTable::preOrder() {
    for (int i = 0; i < 8; i++) {
        cout << "HashTable[ " << i << " ]===> {";
        hashArr[i]->preOrder();
        cout << "}\n\n";
    }
}

void AVLHashTable::inOrder() {
    for (int i = 0; i < 8; i++) {
        cout << "HashTable[ " << i << " ]===> {";
        hashArr[i]->inOrder();
        cout << "}\n\n";
    }
}
