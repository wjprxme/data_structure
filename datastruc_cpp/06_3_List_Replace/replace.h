void replace(const T &x, CP::list<T> &y)
{
  // write your code here
  auto itr = begin();
  while (itr != end()){
    if (*itr == x){
      itr = erase(itr);
      for (auto i : y){
        insert(itr, i);
      }
    }
    else {
      itr++;
    }
  }
}

