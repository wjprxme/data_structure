#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
  //write your code here
  size_t moveindex = (mFront + pos) % mCap;
  T moveelement = mData[moveindex];
  for (size_t i = pos; i > 0; i--) {
      size_t nowindex = (mFront + i) % mCap;
      size_t oldindex = (nowindex - 1 + mCap) % mCap;
      mData[nowindex] = mData[oldindex];
  }
  mData[mFront] = moveelement;
}

#endif