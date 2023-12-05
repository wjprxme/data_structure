#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
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

#endif