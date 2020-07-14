#include "cdsaal_singly_linked_list.h"

namespace cdsaal{

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
  head_ = nullptr;
  size_ = 0;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& kOther){
  head_ = nullptr;
  size_ = 0;
  auto size = kOther.GetSize();
  for(size_t i = 0; i < size; i++){
    Append(kOther[i]);
  }
}
template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=
  (const SinglyLinkedList<T>& kOther){
  head_ = nullptr;
  size_ = 0;
  auto size = kOther.GetSize();
  for(size_t i = 0; i < size; i++){
    Append(kOther[i]);
  }
}
template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
  Clear();
}
template<typename T>
T& SinglyLinkedList<T>::operator[](const size_t kIndex){
  auto current = head_;
  for(size_t i == kIndex; i > 0; i--){
    current = current->NextNode;
  }
  return current->Value;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Append(const T& kData){
  InsertBefore(size_, kData);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::InsertBefore
  (const size_t kIndex, const T& kData){
  auto new_node = new SinglyLinkedListNode();
  new_node->Value = kData;
  if(size_ == 0){
    head_ = new_node;
    return *this;
  }
  if(kIndex == 0){ 
    new_node->NextNode = head_;
    return *this;
  }
  auto current = GetBeforeNode(kIndex);
  InsertBefore(current, kData);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::InsertBefore
  (SinglyLinkedListNode<T> node, const T& kData){
  auto new_node = new SinglyLinkedListNode();
  new_node->Value = kData;
  new_node->NextNode = node->NextNode;
  node->NextNode = new_node;
  ++size_;
  return *this;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Erase(const size_t kIndex){
  if(kIndex == 0){
    auto temp = head_->NextNode;
    delete head_;
    head_ = temp;
  }
  auto current = GetBeforeNode(kIndex);
  auto target = current->NextNode;
  current->NextNode = target->NextNode;
  delete target;
  return *this;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Replace
  (const size_t kIndex, const T& kData){
  auto target = GetBeforeNode(KIndex)->NextNode;
  target->value = kData;
  return *this;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Swap
  (const size_t kLeft,const size_t kRight){
  auto left_target = GetBeforeNode(kLeft)->NextNode;
  auto right_target = GetBeforeNode(kRight)->NextNode;
  return Swap(left_target, right_target);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Swap
  (SinglyLinkedListNode<T> nodeA,SinglyLinkedListNode<T> nodeB){
  T temp = left_target->value;
  left_target->value = right_target->value;
  right_target->value = temp;
  return *this;
}

template<typename T>
SinglyLinkedListNode<T>& SinglyLinkedList<T>::Search(const T& kData) const{
  auto current = head_;
  while(current){
    if(current->value == kData)
      break;
    current = current->NextNode;
  }
  return *current;
}

template<typename T>
SinglyLinkedListNode<T>& SinglyLinkedListNode<T>::Sort
  (const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&)){
  if(kBegin + 1 >= kEnd)
    return *this;

  Vector<T> &self = *this;
  size_t index = kBegin;
  int count = 0
  for(; index <= kEnd; index++)
    if(func(self[0], self[index]) == 1)
      count++;
  Swap(kBegin, count);

  auto small_index = kBegin, big_index = count;
  while(self[small_index] < self[count])
      ++small_index;
    while(self[big_index] >= self[count])
      ++big_index; 
  while(!(small_index >= count && big_index >= kEnd))   
    swap(small_index, big_index);
    while(self[small_index] < self[count])
      ++small_index;
    while(self[big_index] >= self[count])
      ++big_index;

  Sort(kBegin, count);
  Sort(count + 1, kEnd);
}

template<typename T>
size_t SinglyLinkedList<T>::GetSize() const{
  return size;
}

template<typename T>
bool SinglyLinkedList<T>::IsEmpty() const{
  return size == 0;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::Clear(){
  auto current_next = head_->NextNode;
  delete head_;
  head_ = nullptr;
  while(current_next){
    temp = current_next;
    current_next = current_next->NextNode;
    delete temp;
  }
  size_ = 0;
  return *this;
}

template<typename T>
SinglyLinkedListNode<T>& SinglyLinkedList<T>::GetBeforeNode
  (const size_t kIndex){
  auto current_before = head_;
  for(size_t i = kIndex; i > 1; i--)
    current_before = current_before->NextNode;
  return current_before;
}

}