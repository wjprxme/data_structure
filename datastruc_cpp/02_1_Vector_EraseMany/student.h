#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    //write your code here
    std::vector<bool> eraseFlags(mSize, false);

    for (size_t p : pos) {
      eraseFlags[p] = true;
    }

    std::vector<T> newData;
    for (size_t i = 0; i < mSize; i++) {
      if (eraseFlags[i] == false) {
        newData.push_back(mData[i]);
      }
    }

    delete[] mData;
    mData = new T[newData.size()]();
    mSize = newData.size();
    mCap = mSize;

    for (size_t i = 0; i < mSize; i++) {
        mData[i] = newData[i];
    }
}


#endif