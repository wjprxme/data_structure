#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(!ptr->left&& ptr->right)  return process(ptr->right)+1;
  if(!ptr->right && ptr->left) return process(ptr->left)+1;
  if(ptr->right && ptr->left ) return process(ptr->left) + process(ptr->right);
  return 0;  
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
}

#endif

