#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  CP::map_bst<KeyT, MappedT, CompareT> r;
  node *n = mRoot, *temp, *rightRoot;
  while (n != NULL) {
    if (mLess(n->data.first, val)) {
      n = n->right;
    } else {
      temp = n->left;
      if (n == mRoot) {
        mRoot = temp;
        if (n->left != NULL) {
          n->left = NULL;
          temp->parent = NULL;
        }
      } else {
        child_link(n->parent, n->data.first) = temp;
        if (n->left != NULL) {
          temp->parent = n->parent;
          n->left = NULL;
        }
      }
      if (r.mRoot == NULL) {
        r.mRoot = n;
        n->parent = NULL;
      } else {
        n->parent = temp;
        rightRoot->left = n;
      }
      rightRoot = n;
      n = temp;
    }
  }
  return r;
}

#endif

