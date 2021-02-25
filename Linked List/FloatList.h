//
// Created by GM on 22/10/2020.
//

#ifndef INC_1STPROJECT_FLOATLIST_H
#define INC_1STPROJECT_FLOATLIST_H


class FloatList {
    private:
        struct Node{
            float value;
            struct Node* nextNodePtr;
        };

        Node* head;


    public:
        FloatList();
        ~FloatList();
        void appendNode(float num);
        void displayList();
        void deleteNode(float num);
        Node* reverse();
        Node *getHead() const;
        void setHead(Node *head);

};


#endif //INC_1STPROJECT_FLOATLIST_H
