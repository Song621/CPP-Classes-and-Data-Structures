#pragma once

#include "Array.h"

template <class DataType>
class PriorityQueue
{
public:
	PriorityQueue();
	PriorityQueue(const Array<DataType>& arr);
	void enqueue(const DataType& newElement);
	bool dequeue(DataType& remElement);
	bool isEmpty() const;
	void makeEmpty();
private:
	Array<DataType> elements;
	int heapsize;
	inline void heapify(int i);
};

template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
	:elements(2), heapsize(0)
{
}

template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue<DataType>& arr)
	:elements(arr), heapsize(arr.length())
{

}
