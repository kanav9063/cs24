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
    {
        throw std::underflow_error("Heap is empty");
    }

    Entry result = mData[0];
    mData[0] = mData[mCount - 1];
    mCount--;

    size_t i = 0;
    while (true)
    {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left >= mCount)
        {
            break;
        }

        size_t smallerChild = left;
        if (right < mCount && mData[right].score < mData[left].score)
        {
            smallerChild = right;
        }

        if (mData[i].score > mData[smallerChild].score)
        {
            std::swap(mData[i], mData[smallerChild]);
            i = smallerChild;
        }
        else
        {
            break;
        }
    }

    return result;
}

Heap::Entry Heap::pushpop(const std::string& value, float score)
{
    if (mCount == 0)
    {
        throw std::underflow_error("Heap is empty");
    }

    Entry result = mData[0];
    mData[0] = { value, score };

    size_t i = 0;
    while (true)
    {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left >= mCount)
        {
            break;
        }

        size_t smallerChild = left;
        if (right < mCount && mData[right].score < mData[left].score)
        {
            smallerChild = right;
        }

        if (mData[i].score > mData[smallerChild].score)
        {
            std::swap(mData[i], mData[smallerChild]);
            i = smallerChild;
        }
        else
        {
            break;
        }
    }

    return result;
}

void Heap::push(const std::string& value, float score)
{
    if (mCount == mCapacity)
    {
        throw std::overflow_error("Heap is full");
    }

    mData[mCount] = { value, score };
    size_t i = mCount;
    mCount++;

    while (i > 0)
    {
        size_t parent = (i - 1) / 2;

        if (mData[i].score < mData[parent].score)
        {
            std::swap(mData[i], mData[parent]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

const Heap::Entry& Heap::top() const
{
    if (mCount == 0)
        throw std::underflow_error("Heap underflow");
    return mData[0];
}