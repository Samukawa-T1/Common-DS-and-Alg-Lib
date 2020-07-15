#include "dsal_double_linked_list.h"

namespace dsal{

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
  size_ = 0;
  head_ = new DoubleLinkedListNode();
  tail_ = new DoubleLinkedListNode();
  head_ -> NextNode = tail_;
  tail_ -> PrevNode = head_;
}
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& kOther){
  size_ = kOther.GetSize();
  for(size_t i = 0; i < size_; i++)
    Append(kOther[i]);
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
  Clear();
  delete head_;
  delete tail_;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& kOther){
  size_ = kOther.GetSize();
  for(size_t i = 0; i < size_; i++)
    Append(kOther[i]);
  return *this;
}

template<typename T>
T& DoubleLinkedList<T>::operator[](const size_t kIndex){
  auto target = GetNode(kIndex);
  if(target == tail_)
    throw "Over Bounds";
  return target -> Value;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Append(const T& kData){
  return InsertBefore(size_, kData);
}
template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::InsertBefore
    (const size_t kIndex, const T& kData){
  auto before_new = GetNode();
  return InsertBefore(before_new, kData);
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::InsertBefore
    (DoubleLinkedListNode<T>* after_new, const T& kData){
  auto new_node = new DoubleLinkedListNode(kData);
  auto before_new = after_new ->PrevNode;
  new_node -> PrevNode = before_new;
  new_node -> NextNode = after_new;
  before_new -> NextNode = new_node;
  after_new -> PrevNode = new_node;
  ++size_;
  return *this;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Erase(const size_t kIndex){
  auto target = GetNode(kIndex);
  auto prev_node = target -> PrevNode;
  auto next_node = target -> NextNode;
  prev_node -> NextNode = next_node;
  next_node -> PrevNode = prev_node;
  delete target;
  -- size_;
  return *this;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Replace
    (const size_t kIndex, const T& kData){
  auto target = GetNode(kIndex);
  target -> Value = kData;
  return *this;
}
template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Swap
    (const size_t kLeft,const size_t kRight){
  auto node_a = GetNode(kLeft);
  auto node_b = GetNode(kRight);
  Swap(node_a, node_b);
  return *this;
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Swap
    (DoubleLinkedListNode<T>* node_a, DoubleLinkedListNode<T>* node_b){
  auto swap_temp = node_a -> Value;
  node_a -> Value = node_b -> Value;
  node_b -> Value = node_a -> Value;
  return *this;
}
  
template<typename T>
DoubleLinkedListNode<T>* DoubleLinkedList<T>::Search(const T& kData) const{
  auto current = head_ -> NextNode;
  while(current != tail_){
    if(current -> Value == kData)
      break;
    current = current -> NextNode;
  }
  return current;
}
template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Sort
    (const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&)){
  if(kBegin + 1 >= kEnd)
    return *this;

  Vector<T> &self = *this;
  size_t index = kBegin;
  int count = 0
  for(; index <= kEnd; index++)
    if(func(self[kBegin], self[index]) == 1)
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
size_t DoubleLinkedList<T>::GetSize() const{
  return size_;
}

template<typename T>
bool DoubleLinkedList<T>::IsEmpty() const{
  return size_ == 0;
}
template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::Clear(){
  auto current = head_ -> NextNode;
  while(current != tail_){
    auto current_next = current -> NextNode;
    delete current;
    current = current_next;
  }
  head_ -> NextNode = tail_;
  tail_ -> PrevNode = head_;
  return *this;
}

template<typename T>
DoubleLinkedListNode<T>* DoubleLinkedList<T>::GetNode(const size_t kIndex){
  auto mid == size_ << 2;
  auto current = head_;
  if(kIndex <= mid){
    size_t jumps = kIndex + 1;
    while(--jumps >= 0)
      current = current -> NextNode;
  }
  else{
    size_t jumps = size_ - kIndex + 1;
    current = tail_;
    while(--jumps >= 0)
      current = current -> PrevNode;
  }
}
}