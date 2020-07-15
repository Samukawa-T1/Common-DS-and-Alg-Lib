#ifndef CDSAAL_SRC_DS_LIST_DSAL_SINGLY_LINKED_LIST_H
#define CDSAAL_SRC_DS_LIST_DSAL_SINGLY_LINKED_LIST_H

#ifndef CDSAAL_INCLUDE_STDDEF_H
#define CDSAAL_INCLUDE_STDDEF_H
#include <stddef.h>
#endif //CDSAAL_INCLUDE_STDDEF_H

#include "dsal_singly_linked_node.h"

namespace dsal{

template<typename T>
class SinglyLinkedList{
 public:
  SinglyLinkedList();
  SinglyLinkedList(const SinglyLinkedList<T>& kOther);
  ~SinglyLinkedList();
  SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& kOther);
  T& operator[](const size_t kIndex);
  SinglyLinkedList<T>& Append(const T& kData);
  SinglyLinkedList<T>& InsertBefore
    (const size_t kIndex, const T& kData);
  SinglyLinkedList<T>& InsertBefore
    (SinglyLinkedListNode<T> node, const T& kData);
  SinglyLinkedList<T>& Erase(const size_t kIndex);
  SinglyLinkedList<T>& Replace
    (const size_t kIndex, const T& kData);
  SinglyLinkedList<T>& Swap
    (const size_t kLeft,const size_t kRight);
  SinglyLinkedList<T>& Swap
    (SinglyLinkedListNode<T> nodeA, SinglyLinkedListNode<T> nodeB);
  
  SinglyLinkedListNode<T>& Search(const T& kData) const;
  SinglyLinkedListNode<T>& Sort
    (const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&));
  size_t GetSize() const;
  bool IsEmpty() const;
  SinglyLinkedList<T>& Clear();


 private:
  SinglyLinkedListNode<T>& GetBeforeNode(const size_t kIndex);
  SinglyLinkedListNode<T>* head_;
  size_t size_;
};
}

#endif //CDSAAL_SRC_DS_LIST_DSAL_SINGLY_LINKED_LIST_H