#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"


template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  if (k == 1) {
    return mData[0];
  }
  if (k == 2) {
    if (mLess(mData[1], mData[2])) {
      return mData[2];
    }
    else {
      return mData[1];
    }
  }
  if (k == 3) {
    T x;
    if (mLess(mData[1],mData[2])) {
      x = mData[1];
    }
    if (mLess(mData[2],mData[1])) {
      x = mData[2];
    }
    if (mLess(x,mData[3])) {
      x = mData[3];
    }
    if (mLess(x,mData[4])) {
      x = mData[4];
    }
    if (mLess(x,mData[5])) {
      x = mData[5];
    }
    if (mLess(x,mData[6])) {
      x = mData[6];
    }
    return x;
  }
  return mData[0];
}

#endif
