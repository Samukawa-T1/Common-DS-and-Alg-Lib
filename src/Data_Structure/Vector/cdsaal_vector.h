//
//  @License: Apache-2.0
//  @Author: Samukawa-T1 (chogenfran@icloud.com)
//  @Content: Basic Vector Template
//  @Project: Common-DS-and-Alg-Lib (https://git.io/cdsaal)
//  @Version: 0.01 Alpha
//

#ifndef CDSAGL_SRC_DS_VECTOR_H
#define CDSAGL_SRC_DS_VECTOR_H

#include <stddef.h>
#define DEFAULT_SIZE 16
#define EXBAND_FACTOR 1.5

namespace cdsaal{

template<typename T>
class Vector{
 public:
  Vector();
  Vector(const size_t kSize);
  Vector(const Vector<T>& kOther);
  Vector<T>& operator=(const Vector<T>& kOther);
  T& operator[](const size_t kIndex) const;
  ~Vector();

  Vector<T>& Append(const T& kData);
  
  Vector<T>& InsertBefore(const size_t kIndex, const T& kData);
  Vector<T>& Erase(const size_t kIndex);
  Vector<T>& Erase_End();

  Vector<T>& Replace(const size_t kIndex, const T& kData);
  Vector<T>& Swap(const size_t kLeft, const size_t kRight);

  size_t Search(T* data) const;
  Vector<T>& Sort(const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&));
  
  size_t GetSize() const;
  size_t GetCapacity() const;
  bool IsEmpty() const;
  Vector<T>& Clear();
 private:
 size_t size_;
 size_t capacity_;
 T* data_;

 void Expand();
};


}

#endif // CDSAGL_SRC_DS_VECTOR_H