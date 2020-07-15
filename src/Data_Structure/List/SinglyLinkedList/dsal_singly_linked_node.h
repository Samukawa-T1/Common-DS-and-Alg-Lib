#ifndef CDSAAL_SRC_DS_LIST_DSAL_SINGLY_LINKED_NODE_H
#define CDSAAL_SRC_DS_LIST_DSAL_SINGLY_LINKED_NODE_H

namespace dsal{

template<typename T>
struct SinglyLinkedListNode
{
  T Value;
  SinglyListNode* NextNode = nullptr;
};
}
#endif //CDSAAL_SRC_DS_LIST_DSAL_SINGLY_LINKED_NODE_H
