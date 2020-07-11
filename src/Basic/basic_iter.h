//
//  @License: Apache-2.0
//  @Author: Samukawa-T1 (chogenfran@icloud.com)
//  @Content: Basic Iterator Template
//  @Project: Common-DS-and-Alg-Lib (https://git.io/cdsaal)
//  @Version: 0.01 Alpha
//

#ifndef CDSAGL_SRC_BASIC_BASIC_ITER_H
#define CDSAGL_SRC_BASIC_BASIC_ITER_H
namespace cdsaal{

template<typename T>
class basic_iter{
 public:
  basic_iter(T* data_pointer);
  virtual basic_iter<T>& operator++() = 0;
  virtual basic_iter<T>& operator++(int) = 0;
  virtual basic_iter<T>& operator+(int offset) override;
  virtual basic_iter<T>& operator-(int offset) override;
  virtual bool operator==(const basic_iter<T> &other) const;
  virtual bool operator!=(const basic_iter<T> &other) const;
  virtual T& operator*() const;
  virtual T* operator->() const;

 private:
  T* data_pointer_;
};

}
#endif // CDSAGL_SRC_BASIC_BASIC_ITER_H