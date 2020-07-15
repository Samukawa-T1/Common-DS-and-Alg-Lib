#ifndef CDSAAL_SRC_DS_DSAL_VECTOR_H
#define CDSAAL_SRC_DS_DSAL_VECTOR_H

#ifndef CDSAAL_INCLUDE_STDDEF_H
#define CDSAAL_INCLUDE_STDDEF_H
#include <stddef.h>
#endif //CDSAAL_INCLUDE_STDDEF_H

#define DEFAULT_SIZE 16
#define EXBAND_FACTOR 1.5

namespace dsal{

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
  Vector<T>& Sort
  (const size_t kBegin, const size_t kEnd,int (func)(const T&,const T&));
  
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

#endif // CDSAAL_SRC_DS_DSAL_VECTOR_H