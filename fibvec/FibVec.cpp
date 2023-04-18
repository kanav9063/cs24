#include "FibVec.h"

// This provides exception types:
#include <stdexcept>

FibVec* create_fibvec() {
  // Used by the autograder to make a new FibVec.
  // You shouldn't need to change this.
  return new FibVec();
}


// FibVec Function Implementations
FibVec::FibVec() {
  v = new int[1]; // create buffer with capacity f(2) = 1
  v_capacity= 1;
  v_count = 0;
}

FibVec::~FibVec() {
  delete[] v;
}
 
// Member Functions
size_t FibVec::capacity() const {
  return v_capacity;
}

size_t FibVec::count() const {
  return v_count;
}

size_t FibVec::next_fib(size_t n) const {
  if (n <= 1) {
    return 1;
  }
  size_t a = 1;
  size_t b = 1;
  while (b < n) {
    size_t temp = b;
    b += a;
    a = temp;
  }
  return b;
}

void FibVec::insert(int value, size_t index) {
  if (index > v_count) {
    throw std::out_of_range("out of range");
  }

  if (v_count >= v_capacity) {
    cap_change(next_fib(v_capacity + 1));
  }
   for (size_t i = v_count; i > index; --i) {
    v[i] = v[i-1];
  }
  v[index] = value;
  v_count=v_count+1;
}

void FibVec::push(int value) {
  insert(value, v_count);
}

int FibVec::lookup(size_t index) const {
  if (index >= v_count) {
    throw std::out_of_range("out of range");
  }
  return v[index];
}

int FibVec::pop() {
  if (v_count == 0) {
    throw std::out_of_range("out of range");
  }
  int value = remove(v_count-1);
  return value;
}

int FibVec::remove(size_t index) {
  if (index >= v_count) {
    throw std::out_of_range("out of range");
  }

  int value = v[index];
  for (int i = index; i < (int)(v_count) - 1; ++i) {
    v[i] = v[i+1];
  }
  v_count = v_count - 1;

  cap_downsize();



  return value;
}

void FibVec::cap_change(size_t newCapacity) {
    int* newBlock = new int[newCapacity];
    for (size_t i = 0; i < v_count; i++) {
        newBlock[i] = v[i];
    }
    delete[] v;
    v = newBlock;
    v_capacity = newCapacity;
}

void FibVec::cap_downsize() {
  size_t prev_fib = 1;
  size_t curr_fib = 1;

  while (curr_fib <= v_count) {
    size_t temp = curr_fib;
    curr_fib += prev_fib;
    prev_fib = temp;
  }

  if (v_count < (curr_fib-prev_fib)) {
    size_t new_capacity = prev_fib;
    int* new_block = new int[new_capacity];
    for (size_t i = 0; i < v_count; i++) {
      new_block[i] = v[i];
    }
    delete[] v;
    v = new_block;
    v_capacity = new_capacity;
  }
}



