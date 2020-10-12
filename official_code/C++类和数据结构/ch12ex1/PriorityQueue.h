// PriorityQueue.h -- a heap (array) implementation of a priority queue#include "Array.h"// if a struct is used as DataType //		operator > must be overloaded for comparing two elements of DataType// if a PriorityQueue is constructed passing in an Array object, the length function of the//		Array object must return exactly the number of elements to be put in the heap//		(use the changeSize function if necessary)// The constructors, the enqueue function, the (default) copy constructor, and// the (default) assignment can cause an exception to be thrown if out of heap memorytemplate <class DataType>class PriorityQueue{public:	PriorityQueue( );	PriorityQueue( const Array<DataType> & arr );	void enqueue( const DataType & newElement );  	bool dequeue( DataType & remElement );	// returns false if heap is empty											// otherwise returns true; use isEmpty before											// use if necessary	bool isEmpty( ) const;	void makeEmpty( );private:	Array<DataType> elements;	int heapsize;	inline void heapify( int i );	// assumes the subtree rooted at i is a heap, except for									// node i; turns this subtree into a heap};#include "PriorityQueue.cpp"