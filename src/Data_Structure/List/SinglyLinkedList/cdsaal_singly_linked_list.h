//
//  @License: Apache-2.0
//  @Author: Samukawa-T1 (chogenfran@icloud.com)
//  @Content: Singly Linked List Template
//  @Project: Common-DS-and-Alg-Lib (https://git.io/cdsaal)
//  @Version: 0.01 Alpha
//

#ifndef CDSAGL_SRC_DS_LIST_SINGLY_LINKED_LIST_H
#define CDSAGL_SRC_DS_LIST_SINGLY_LINKED_LIST_H

#include <stddef.h>

#include "cdsaal_singly_linked_node.h"

namespace cdsaal{

template<typename T>
class SinglyLinkedList{
 public:
  SinglyLinkedList();
  SinglyLinkedList(const SinglyLinkedList<T>& kOther);
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

#endif //CDSAGL_SRC_DS_LIST_SINGLY_LINKED_LIST_H