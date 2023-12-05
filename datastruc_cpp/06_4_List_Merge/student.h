#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  // write your code
  auto ls_itr = ls.begin();
  for(int i = 0; i < ls.size(); i++){
    mSize += (*ls_itr).size();

    if((*ls_itr).mSize > 0){
      (*ls_itr).begin().ptr->prev = mHeader->prev;
      mHeader->prev->next = (*ls_itr).begin().ptr;

      auto lastData = (*ls_itr).end();
      lastData--;
      mHeader->prev = lastData.ptr;
      lastData.ptr->next = mHeader;

      (*ls_itr).end().ptr->prev = (*ls_itr).end().ptr;
      (*ls_itr).end().ptr->next = (*ls_itr).end().ptr;
    }

    (*ls_itr).mSize = 0;
    ls_itr++;
  }
}

#endif

