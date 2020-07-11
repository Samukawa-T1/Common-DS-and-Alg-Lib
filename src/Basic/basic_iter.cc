#include "basic_iter.h"

namespace cdsaal{

template <typename T>
basic_iter<T>::basic_iter(T *data_pointer){
  data_pointer_ = data_pointer;
}

template <typename T>
basic_iter<T>& basic_iter<T>::operator+(int offset){
  data_pointer_ += offset;
  return *this;
}

template <typename T>
basic_iter<T>& basic_iter<T>::operator-(int offset){
  data_pointer_ -= offset;
  return *this;
}

template <typename T>
bool basic_iter<T>::operator==(const basic_iter<T> &other) const{
  return other.data_pointer_ == data_pointer_;
}

template <typename T>
bool basic_iter<T>::operator!=(const basic_iter<T> &other) const{
  return other.data_pointer_ != data_pointer_;
}

template <typename T>
T& basic_iter<T>::operator*() const{
  return *data_pointer_;
}

template <typename T>
T* basic_iter<T>::operator->() const{
  return data_pointer_;
}
}