#include "Heap.h"
#include <stdexcept>

Heap::Heap(size_t capacity)
    : mData(new Entry[capacity]), mCapacity(capacity), mCount(0)
{
}

Heap::Heap(const Heap& other)
    : mData(new Entry[other.mCapacity]), mCapacity(other.mCapacity), mCount(other.mCount)
{
    for (size_t i = 0; i < mCount; i++) {
        mData[i] = other.mData[i];
    }
}

Heap::Heap(Heap&& other)
    : mData(other.mData), mCapacity(other.mCapacity), mCount(other.mCount)
{
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mCount = 0;
}

Heap::~Heap()
{
    delete[] mData;
}

size_t Heap::capacity() const
{
    return mCapacity;
}

size_t Heap::count() const
{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const
{
    if (index >= mCount)
        throw std::out_of_range("Index out of range");
    return mData[index];
}

Heap::Entry Heap::pop()
{
    if (mCount == 0)
        throw std::underflow_error("Heap underflow");

    Entry entry = mData[0];
    mData[0] = mData[mCount - 1];
    mCount--;

    size_t current = 0;
    bool percolateDown = true;
    while (percolateDown) {
        size_t leftChild = current * 2 + 1;
        size_t rightChild = current * 2 + 2;
        size_t smallest = current;

        if (leftChild < mCount && mData[leftChild].score < mData[smallest].score)
            smallest = leftChild;

        if (rightChild < mCount && mData[rightChild].score < mData[smallest].score)
            smallest = rightChild;

        if (smallest == current)
            percolateDown = false;
        else {
            Entry temp = mData[current];
            mData[current] = mData[smallest];
            mData[smallest] = temp;
            current = smallest;
        }
    }

    return entry;
}

void Heap::push(const std::string& value, float score)
{
    if (mCount == mCapacity)
        throw std::overflow_error("Heap overflow");

    size_t current = mCount;
    mData[current] = { value, score };
    mCount++;

    bool percolateUp = true;
    while (current != 0 && percolateUp) {
        size_t parent = (current - 1) / 2;
        if (mData[current].score >= mData[parent].score)
            percolateUp = false;
        else {
            Entry temp = mData[current];
            mData[current] = mData[parent];
            mData[parent] = temp;
            current = parent;
        }
    }
}

Heap::Entry Heap::pushpop(const std::string& value, float score)
{
    if (mCount == 0)
        throw std::underflow_error("Heap underflow");

    Entry entry = mData[0];
    if (score >= entry.score)
        return entry;

    mData[0] = { value, score };

    size_t current = 0;
    bool percolateDown = true;
    while (percolateDown) {
        size_t leftChild = current * 2 + 1;
        size_t rightChild = current * 2 + 2;
        size_t smallest = current;

        if (leftChild < mCount && mData[leftChild].score < mData[smallest].score)
            smallest = leftChild;

        if (rightChild < mCount && mData[rightChild].score < mData[smallest].score)
            smallest = rightChild;

        if (smallest == current)
            percolateDown = false;
        else {
            Entry temp = mData[current];
            mData[current] = mData[smallest];
            mData[smallest] = temp;
            current = smallest;
        }
    }

    return entry;
}

const Heap::Entry& Heap::top() const
{
    if (mCount == 0)
        throw std::underflow_error("Heap underflow");
    return mData[0];
}