#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T> > data) {
  //write your code here
  int oldmSize = mSize;
  T *newarr = new T[(mSize + 1) * 2]();

  for (size_t i = 0; i < mSize; i++) {
    newarr[(2 * i) + 1] = mData[i];
  }

  for (const auto &pair : data) {
    newarr[2 * pair.first] = pair.second;
  }

  mData = newarr;
  mSize = 0;

  for (size_t i = 0; i < (oldmSize+1)*2; i++) {
    if (newarr[i] != T()) {
      mData[mSize] = newarr[i];
      mSize++;
    }
  }
}

#endif
