#ifndef _CP_VECTOR_INCLUDED_
#define _CP_VECTOR_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP {

template <typename T>
class vector
{
  public:
    typedef T* iterator;

  protected:
    T *mData;
    size_t mCap;
    size_t mSize;

    void rangeCheck(int n) {
      if (n < 0 || (size_t)n >= mSize) {
        throw std::out_of_range("index of out range") ;
      }
    }

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void ensureCapacity(size_t capacity) {
      if (capacity > mCap) {
        size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
        expand(s);
      }
    }

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    vector(const vector<T>& a) {
      mData = new T[a.capacity()]();
      mCap = a.capacity();
      mSize = a.size();
      for (size_t i = 0;i < a.size();i++) {
        mData[i] = a[i];
      }
    }
    
    // default constructor
    vector() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
    }

    // constructor with initial size
    vector(size_t cap) {
      mData = new T[cap]();
      mCap = cap;
      mSize = cap;
    }

    // copy assignment operator using copy-and-swap idiom
    vector<T>& operator=(vector<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mSize, other.mSize);
      swap(this->mCap, other.mCap);
      swap(this->mData, other.mData);
      return *this;
    }

    ~vector() {
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    size_t capacity() const {
      return mCap;
    }

    void resize(size_t n) {
      if (n > mCap)
        expand(n);

      if (n > mSize) {
        T init = T();
        for (size_t i = mSize;i < n;i++) 
          mData[i] = init;
      }
      mSize = n;
    }

    //----------------- iterator ---------------
    iterator begin() {
      return &mData[0];
    }

    iterator end() {
      return begin()+mSize;

    }
    //----------------- access -----------------
    T& at(int index) {
      rangeCheck(index);
      return mData[index];
    }

    T& at(int index) const {
      rangeCheck(index);
      return mData[index];
    }

    T& operator[](int index) {
      return mData[index];
    }

    T& operator[](int index) const {
      return mData[index];
    }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void pop_back() {
      mSize--;
    }

    iterator insert(iterator it,const T& element) {
      size_t pos = it - begin();
      ensureCapacity(mSize + 1);
      for(size_t i = mSize;i > pos;i--) {
        mData[i] = mData[i-1];
      }
      mData[pos] = element;
      mSize++;
      return begin()+pos;
    }

    void erase(iterator it) {
      while((it+1)!=end()) {
        *it = *(it+1);
        it++;
      }
      mSize--;
    }

    void clear() {
      mSize = 0;
    }


    //-------------- extra (unlike STL) ------------------
    int index_of(const T& element) {
      for (int i = 0;i < mSize;i++) {
        if (mData[i] == element) {
          return i;
        }
      }
      return -1;
    }

    bool contains(const T& element) {
      return index_of(element) != -1;
    }

    void insert_by_pos(size_t it,const T& element) {
      insert(begin()+it,element);
    }

    void range_insert(iterator position,iterator first,iterator last) {
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

    void insert_many(CP::vector<std::pair<int,T> > data) {
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

    void erase_by_pos(int index) {
      erase(begin()+index);
    }

    void erase_by_value(const T& element) {
      int i = index_of(element);
      if (i != -1) erase_by_pos(i);
    }

    void erase_many(const std::vector<int> &pos) {
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

    void compress() {
      T *newArr = new T[mSize]();
      for (size_t i = 0; i < mSize; i++) {
          newArr[i] = mData[i];
      }
      delete[] mData;
      mData = newArr;
      mCap = mSize;
    }

    vector<T> Union(const vector<T>& A, const vector<T>& B) {
      vector<T> v;
      v = A;
      for (auto& i : B) {
        if (find(v.begin(), v.end(), i) == v.end()) {
          v.push_back(i);
        }
      }
      return v;
    }

    vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
      vector<T> v;
      for (auto& i : A) {
        if (find(B.begin(), B.end(), i) != B.end()) {
          v.push_back(i);
        }
      }
      return v;
    }

    void uniq() {
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

    bool block_swap(iterator a, iterator b, size_t m) {
      if (a > b) {
        std::swap (a, b);
      }
      if (m == 0 || a + m > b || b + m > end() || a < begin() || b < begin()) {
        return false;
      }
      while (m > 0) {
        m--;
        std::swap (*(a + m), *(b + m));
      }
      return true;
    }
};
}
#endif