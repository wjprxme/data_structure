#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <set>
//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  std::set<T> s;
  int i = 0;
    for (int j = 0; j < mSize; j++) {
        if (s.find(mData[j]) == s.end()) {
            mData[i] = mData[j];
            s.insert(mData[j]);
            i++;
        }
    }
    mSize = i;
}

#endif
