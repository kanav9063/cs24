#ifndef FIBVEC_H
#define FIBVEC_H

#include <cstddef>
#include <stdexcept>

class FibVec {
public:
  FibVec();
  ~FibVec();
 
  size_t capacity() const;
  size_t count() const;
  void insert(int value, size_t index);
  void push(int value);
  int lookup(size_t index) const;
  int pop();
  int remove(size_t index);
  void downsize(); 

private:
  int* v;
  size_t v_capacity;
  size_t v_count;
  size_t next_fib(size_t n) const;
  void cap_change(size_t new_capacity);
};

FibVec* create_fibvec();

#endif