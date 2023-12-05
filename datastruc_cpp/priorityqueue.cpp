#ifndef _CP_PRIORITY_QUEUE_INCLUDED_
#define _CP_PRIORITY_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP {

template <typename T,typename Comp = std::less<T> >

class priority_queue
{
  protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void fixUp(size_t idx) {
      T tmp = mData[idx];
      while (idx > 0) {
        size_t p = (idx - 1) / 2;
        if ( mLess(tmp,mData[p]) ) break;
        mData[idx] = mData[p];
        idx = p;
      }
      mData[idx] = tmp;
    }

    void fixDown(size_t idx) {
      T tmp = mData[idx];
      size_t c;
      while ((c = 2 * idx + 1) < mSize) {
        if (c + 1 < mSize && mLess(mData[c],mData[c + 1]) ) c++;
        if ( mLess(mData[c],tmp) ) break;
        mData[idx] = mData[c];
        idx = c;
      }
      mData[idx] = tmp;
    }

    void print() {
      for (size_t i = 0;i < mSize;i++)
        std::cout << mData[i] << " ";
      std::cout << std::endl;
    }

  public:
    //-------------- constructor ----------

    // copy constructor
    priority_queue(const priority_queue<T,Comp>& a) :
      mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize), mLess(a.mLess)
    {
      for (size_t i = 0; i < a.mCap;i++) {
        mData[i] = a.mData[i];
      }
    }

    // default constructor
    priority_queue(const Comp& c = Comp() ) :
       mData( new T[1]() ),
       mCap( 1 ),
       mSize( 0 ),
       mLess( c )
    { }


    // copy assignment operator
    priority_queue<T,Comp>& operator=(priority_queue<T,Comp> other) {
      using std::swap;
      swap(mSize,other.mSize);
      swap(mCap,other.mCap);
      swap(mData,other.mData);
      swap(mLess,other.mLess);
      return *this;
    }

    ~priority_queue() {
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    //----------------- access -----------------
    const T& top() {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[0];
    }

    //----------------- modifier -------------
    void push(const T& element) {
      if (mSize + 1 > mCap)
        expand(mCap * 2);
      mData[mSize] = element;
      mSize++;
      fixUp(mSize-1);
    }

    void pop() {
      if (size() == 0) throw std::out_of_range("index of out range");
      mData[0] = mData[mSize-1];
      mSize--;
      fixDown(0);
    }

    T get_kth(size_t k) const {
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

    size_t get_rank(size_t pos) const {
      int rank = 0;
      for (int i = 0; i < mSize; i++) {
        if (mLess(mData[pos], mData[i])) {
          rank++;
        }
      }
      return rank;
    }

    void erase(const T& v) {
      for (int i = 0; i < mSize; i++) {
        if (mData[i] == v){
          std::swap(mData[mSize - 1], mData[i]);
          mSize--;
          fixUp(i);
          fixDown(i);
          break;
        }
      }
    }

#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};

class artist_title_count {
public:
  bool operator() (const Song& a, const Song& b) {
    if (a.artist == b.artist) {
      if (a.title == b.title) {
        return a.count > b.count;
      }
      return a.title > b.title;
    }
    return a.artist > b.artist;
  }
};

class count_artist_title {
public:
  bool operator() (const Song& a, const Song& b) {
    if (a.count == b.count) {
      if (a.artist == b.artist) {
        return a.title > b.title;
      }
      return a.artist > b.artist;
    }
    return a.count < b.count;
  }
};

//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2

CP::priority_queue<Song, artist_title_count> pq1;
CP::priority_queue<Song, count_artist_title> pq2;
};

#endif
}
#endif


