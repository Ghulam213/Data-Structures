//
// Created by GM on 20/11/2020.
//

#include "ExpressionValidator.h"

bool ExpressionValidator::validate(string exp) {
    stack.clear();
    for (char i : exp){
        if (i == '{' || i == '[' || i == '(' )
            stack.push(i);
        else if (i == '}' || i == ']' || i == ')')
            stack.pop();
        else
            continue;
    }
    return stack.isEmpty();
}
