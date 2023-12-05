#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    std::vector<T> v;
    int pos = 0;
    while (pos <= b) {
        v.push_back(top());
        pop();
        pos++;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (i >= a && i <= b){
            push(v[i]);
            push(v[i]);
        } 
        else {
            push(v[i]);
        }
    }
}

#endif