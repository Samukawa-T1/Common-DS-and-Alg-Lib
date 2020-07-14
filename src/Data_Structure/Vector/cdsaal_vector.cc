#include "cdsaal_vector.h"

namespace cdsaal{

template<typename T>
Vector<T>::Vector():Vector(DEFAULT_SIZE){};

template<typename T>
Vector<T>::Vector(const size_t kIndex){
  capacity_ = kSize;
  size_ = 0;
  data_ = new T[capacity_];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& kOther){
  capacity_ = kOther.GetCapacity();
  data_ = new T[capacity_];
  int other_size = kOther.GetSize();
  for(size_t i = 0; i < other_size; i++)
    Append(kOther[i]);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& kOther){
  capacity_ = kOther.GetCapacity();
  data_ = new T[capacity_];
  int other_size = kOther.GetSize();
  for(size_t i = 0; i < other_size; i++)
    Append(kOther[i]);
  return *this;
}

template<typename T>
T& Vector<T>::operator[](const size_t kIndex) const{
  return *(data_ + kIndex);
}

template<typename T>
Vector<T>::~Vector(){
  delete []data_;
}

template<typename T>
Vector<T>& Vector<T>::Append(const T& kData){
  if (size_ + 1 >= capacity_)
    Expand();

  (*this)[size_++] = kData;
  return *this;
}

template<typename T>
Vector<T>& Vector<T>::InsertBefore(const size_t kIndex, const T& kData){
  if (size_ + 1 >= capacity_)
    Expand();

  Vector<T> &self = *this;
  for (auto i = size_; i >= kIndex; i--)
    self[i+1] = self[i];
  self[kIndex] = kData;
  return *this;
}

template<typename T>
Vector<T>& Vector<T>::Erase(const size_t kIndex){
  Vector<T> &self = *this;
  for (auto i = size_ - 1; i >= kIndex; i--)
    self[i] = self[i + 1];
}

template<typename T>
Vector<T>& Vector<T>::Erase_End(){
  size_ --;
  return *this;
}

template<typename T>
Vector<T>& Vector<T>::Replace(const size_t kIndex, const T& kData){
  (*this)[kIndex] = kData;
}

template<typename T>
Vector<T>& Vector<T>::Swap(const size_t kLeft, const size_t kRight){
  auto temp = (*this)[kLeft]
  (*this)[kLeft] = (*this)[kRight];
  (*this)[kRight] = (*this)[kLeft];
  return *this;
}

template<typename T>
size_t Vector<T>::Search(T* data) const{
  size_t index = 0;
  for(; index < size_; index++)
    if (*(data_ + index) == T)
      break;
  return index;
}

template<typename T>
Vector<T>& Vector<T>::Sort(const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&)){
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
size_t Vector<T>::GetSize() const{
  return size_;
}

template<typename T>
size_t Vector<T>::GetCapacity() const{
  return capacity_;
}

template<typename T>
bool Vector<T>::IsEmpty() const{
  return size_ == 0;
}

template<typename T>
Vector<T>& Vector<T>::Clear(){
  size_ = 0;
  return *this;
}

template<typename T>
void Vector<T>::Expand(){
  capacity_ *= EXBAND_FACTOR;
  auto new_data = new T[capacity_];

  Vector<T> &src_v = *this;
  Vector<T> &des_v = *new_data;
  for(size_t i = 0; i < size_; i++)
    des_v[i] = src_v[i];
  
  delete []data_;
  data_ = new_data;
  new_data = nullptr;
}
}