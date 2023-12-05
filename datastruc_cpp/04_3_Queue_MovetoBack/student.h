#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
    //your code here
    size_t moveindex = (mFront + pos) % mCap;
    T moveelement = mData[moveindex];
    for (size_t i = pos; i < mSize; i++) {
        size_t nowindex = (mFront + i) % mCap;
        size_t oldindex = (nowindex + 1) % mCap;
        mData[nowindex] = mData[oldindex];
    }
    mData[(mFront + mSize - 1) % mCap] = moveelement;
}

#endif

