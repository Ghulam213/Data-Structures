//
// Created by GM on 20/11/2020.
//

#ifndef LAB5_EXPRESSIONVALIDATOR_H
#define LAB5_EXPRESSIONVALIDATOR_H


#include "CharStack.h"

class ExpressionValidator {
    private:
        CharStack stack;
    public:
        bool validate(string exp);

};


#endif //LAB5_EXPRESSIONVALIDATOR_H
