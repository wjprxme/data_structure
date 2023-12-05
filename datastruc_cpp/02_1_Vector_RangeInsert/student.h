#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  T *newmData = new T[mSize + last - first];
  mSize += last - first;
  mCap = mSize;
  int pos = position - begin();
  int end = pos + last - first;
  int old = 0;
  for (int i = 0; i < mSize; i++) {
    if (i >= pos && i < end) {
      newmData[i] = *(first);
      first++;
    }
    else {
      newmData[i] = mData[old];
      old++;
    }
  }
  delete[] mData;
  mData = newmData;
}

#endif
