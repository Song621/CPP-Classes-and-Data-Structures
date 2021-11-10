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
PriorityQueue<DataType>::PriorityQueue(const Array<DataType>& arr)
	:elements(arr), heapsize(arr.length())
{
	for (int i = (heapsize - 2) >> 1; i >= 0; i--)
	{
		heapify(i);
	}

	int tryPower = 2;
	for (; tryPower < elements.length(); tryPower <<= 1);

	if (tryPower != elements.length())
		elements.changeSize(tryPower);
}

template <class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& newElement)
{
	if (heapsize == elements.length())
		elements.changeSize(elements.length() << 1);

	int i = heapsize;
	for (; (i != 0) && newElement > elements[(i - 1) >> 1]; i = (i - 1) >> 1)
		elements[i] = elements[(i - 1) >> 1];

	elements[i] = newElement;
	heapsize++;
}

template <class DataType>
bool PriorityQueue<DataType>::dequeue(DataType& remElements)
{
	if (!heapsize)
		return false;
	remElements = elements[0];
	heapsize--;
	elements[0] = elements[heapsize];
	heapify(0);

	int trysize = elements.length();
	while ((heapsize <= trysize >> 2) && trysize > 2)
		trysize >>= 1;

	if (trysize < elements.length()) {
		try {
			elements.changeSize(trysize);
		}
		catch(...){}
	}

	return true;
}


template <class DataType>
bool PriorityQueue<DataType>::isEmpty() const
{
	return !heapsize;
}

template <class DataType>
void PriorityQueue<DataType>::makeEmpty()
{
	heapsize = 0;
	try {
		elements.changeSize(2);
	}
	catch(...){ }
}

template <class DataType>
inline void PriorityQueue<DataType>::heapify(int i)
{
	int leftChild, rightChild, largest;
	bool stop = false;

	DataType temp = elements[i];

	leftChild = (i << 1) + 1;
	while (leftChild < heapsize && !stop)
	{
		rightChild = leftChild + 1;
		largest = (rightChild == heapsize) ? leftChild : ((elements[leftChild] > elements[rightChild]) ? leftChild : rightChild);
		if (elements[largest] > temp) {
			elements[i] = elements[largest];
			i = largest;
			leftChild = (i << 1) + 1;
		}
		else
			stop = true;
	}
	elements[i] = temp;
}