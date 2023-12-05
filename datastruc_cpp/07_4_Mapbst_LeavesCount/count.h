#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if (n->left == NULL && n->right == NULL) {
    return 1;
  }
  else if (n->left != NULL && n->right == NULL) {
    return leaves_count(n->left);
  }
  else if (n->left == NULL && n->right != NULL) {
    return leaves_count(n->right);
  }
  else {
    return leaves_count(n->left) + leaves_count(n->right);
  }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
}


#endif
