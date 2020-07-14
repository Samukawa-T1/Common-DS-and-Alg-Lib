//
//  @License: Apache-2.0
//  @Author: Samukawa-T1 (chogenfran@icloud.com)
//  @Content: Singly Linked List Node Template
//  @Project: Common-DS-and-Alg-Lib (https://git.io/cdsaal)
//  @Version: 0.01 Alpha
//
#ifndef CDSAGL_SRC_DS_LIST_LINGLY_LINKED_NODE_H
#define CDSAGL_SRC_DS_LIST_LINGLY_LINKED_NODE_H
#include <stddef.h>
namespace cdsaal{

template<typename T>
struct SinglyLinkedListNode
{
  T Value;
  SinglyListNode* NextNode = nullptr;
};

template<typename T>
struct DoubleLinkedListNode
{
  DoubleListNode* PrevNode = nullptr;
  T Value;
  DoubleListNode* NextNode = nullptr;
};
}
#endif //CDSAGL_SRC_DS_LIST_LINGLY_LINKED_NODE_H
