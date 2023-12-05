void splitList(list<T>& list1, list<T>& list2) {
      int pos = (size() + 1) / 2;
      iterator it = begin();
      for(int i = 0 ;i < pos;i++){
          it++;
      }

      (list1.mHeader)->prev->next = mHeader->next;
      (list1.mHeader)->prev->next->prev = (list1.mHeader)->prev ;
      (list1.mHeader)->prev = (it.ptr)->prev;
      (list1.mHeader)->prev->next = list1.mHeader;
      list1.mSize = pos;

      (list2.mHeader)->prev->next = it.ptr;
      (list2.mHeader)->prev->next->prev = (list2.mHeader)->prev;
      (list2.mHeader)->prev = mHeader->prev;
      (list2.mHeader)->prev->next = list2.mHeader;
      list2.mSize = mSize - pos;

      mSize = 0;
      mHeader->next = mHeader;
      mHeader->prev = mHeader;
    }