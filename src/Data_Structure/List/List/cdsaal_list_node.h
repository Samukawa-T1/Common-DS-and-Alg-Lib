#ifndef CDSAGL_SRC_DS_LIST_NODE_H
#define CDSAGL_SRC_DS_LIST_NODE_H
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
#endif //CDSAGL_SRC_DS_LIST_NODE_H
