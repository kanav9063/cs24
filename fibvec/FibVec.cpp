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

void FibVec::insert(int value, size_t index) {
}


void FibVec::push(int value) {
  insert(value, v_count);
}

int FibVec::lookup(size_t index) const {
  return 1;
}

int FibVec::pop() {
  return 1;
}

int FibVec::remove(size_t index) {}

  //
