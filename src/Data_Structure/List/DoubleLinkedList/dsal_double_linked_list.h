#ifndef CDSAAL_SRC_DS_LIST_DSAL_DOUBLE_LINKED_LIST_H
#define CDSAAL_SRC_DS_LIST_DSAL_DOUBLE_LINKED_LIST_H

#include <stddef.h>

#include "dsal_double_linked_list_node.h"

namespace dsal{

template<typename T>
class DoubleLinkedList{
 public:
  DoubleLinkedList();
  DoubleLinkedList(const DoubleLinkedList<T>& kOther);
  ~DoubleLinkedList();
  DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& kOther);
  T& operator[](const size_t kIndex);
  DoubleLinkedList<T>& Append(const T& kData);
  DoubleLinkedList<T>& InsertBefore
    (const size_t kIndex, const T& kData);
  DoubleLinkedList<T>& InsertBefore
    (DoubleLinkedListNode<T>* node, const T& kData);
  DoubleLinkedList<T>& Erase(const size_t kIndex);
  DoubleLinkedList<T>& Replace
    (const size_t kIndex, const T& kData);
  DoubleLinkedList<T>& Swap
    (const size_t kLeft,const size_t kRight);
  DoubleLinkedList<T>& Swap
    (DoubleLinkedListNode<T>* nodeA, DoubleLinkedListNode<T>* nodeB);
  
  DoubleLinkedListNode<T>* Search(const T& kData) const;
  
  DoubleLinkedList<T>& Sort
    (const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&));
  
  size_t GetSize() const;
  bool IsEmpty() const;
  DoubleLinkedList<T>& Clear();


 private:
  DoubleLinkedListNode<T>* GetNode(const size_t kIndex);
  DoubleLinkedListNode<T>* head_;
  DoubleLinkedListNode<T>* tail_;
  size_t size_;
};
}

#endif //CDSAAL_SRC_DS_LIST_DSAL_DOUBLE_LINKED_LIST_H