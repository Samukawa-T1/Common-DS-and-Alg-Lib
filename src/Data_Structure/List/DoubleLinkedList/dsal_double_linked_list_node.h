#ifndef CDSAAL_SRC_DS_LIST_DSAL_DOUBLE_LINKED_NODE_H
#define CDSAAL_SRC_DS_LIST_DSAL_DOUBLE_LINKED_NODE_H

#ifndef CDSAAL_INCLUDE_STDDEF_H
#define CDSAAL_INCLUDE_STDDEF_H
#include <stddef.h>
#endif //CDSAAL_INCLUDE_STDDEF_H

namespace dsal{

template<typename T>
struct DoubleLinkedListNode
{
  DoubleLinkedListNode() = default;
  DoubleLinkedListNode(const T& kData):Value(kData){}
  DoubleListNode* PrevNode = nullptr;
  T Value;
  DoubleListNode* NextNode = nullptr;
};
}
#endif //CDSAAL_SRC_DS_LIST_DSAL_DOUBLE_LINKED_NODE_H