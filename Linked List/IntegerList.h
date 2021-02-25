//
// Created by GM on 22/10/2020.
//

#ifndef INC_1STPROJECT_FLOATLIST_H
#define INC_1STPROJECT_FLOATLIST_H


class IntegerList {
    private:
        struct Node{
            int value;
            struct Node* nextNodePtr;
        };

        Node* head;

    public:
        IntegerList();
        ~IntegerList();
        void insertAtHead(int num);
        void insertAtLocation(int loc, int num);
        void displayList();
        void deleteNode(int num);
        void countList();
        void deleteAtHead();

};


#endif //INC_1STPROJECT_FLOATLIST_H
