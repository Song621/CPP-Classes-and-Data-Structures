// PriorityQueue.cpp -- function definitions for the heap (array) implementation of //		a priority queuetemplate <class DataType>PriorityQueue<DataType>::PriorityQueue( )	: elements( 2 ), heapsize( 0 ){}template <class DataType>PriorityQueue<DataType>::PriorityQueue( const Array<DataType> & arr )	: elements( arr ), heapsize( arr.length( ) ){	for ( int i = ( heapsize - 2 ) >> 1; i >= 0; i-- )		heapify( i );	// change elements capacity to the next power of 2, for use in dequeue function	int tryPower = 2;	for ( ; tryPower < elements.length( ); tryPower <<= 1 );	if ( tryPower != elements.length( ) ) 		elements.changeSize( tryPower );}template <class DataType>void PriorityQueue<DataType>::enqueue( const DataType & newElement ){	if ( heapsize == elements.length( ) )		elements.changeSize( elements.length( ) << 1 );	// reheap upwards from the bottom	int i = heapsize;	for ( ; (i != 0) && newElement > elements[ (i - 1) >> 1 ]; i = ( i - 1 ) >> 1 )   		elements[ i ] = elements[ ( i - 1 ) >> 1 ];	elements[ i ] = newElement;	heapsize++;}						// returns false if trying to dequeue from an empty heap; otherwise returns truetemplate <class DataType>bool PriorityQueue<DataType>::dequeue( DataType & remElement ){	if ( !heapsize )		return false;	remElement = elements[ 0 ];	heapsize--;	elements[ 0 ] = elements[ heapsize ];	heapify( 0 );	// try to get the lowest power of 2 which is at least 2 and at least twice the	// size of the used portion of the array; use this for the new capacity to conserve	// memory	int trysize = elements.length( );	while ( ( heapsize <= trysize >> 2 ) && trysize > 2 ) 		trysize >>= 1;	if ( trysize < elements.length( ) ) {		try {			elements.changeSize( trysize );		}		catch ( ... ) {}	}	return true;}template <class DataType>bool PriorityQueue<DataType>::isEmpty( ) const{	return !heapsize;}template <class DataType>void PriorityQueue<DataType>::makeEmpty( ){	heapsize = 0;	try {		elements.changeSize( 2 );	}	catch( ... ) { }}// assumes that the subtree rooted at i is a heap except for node i;// turns this subtree into a heaptemplate <class DataType>inline void PriorityQueue<DataType>::heapify( int i ){	int leftChild, rightChild, largest;	bool stop = false;	DataType temp = elements[ i ];	leftChild = (i << 1) + 1;	while ( leftChild < heapsize && !stop ) {		rightChild = leftChild + 1;		largest = ( rightChild == heapsize )? leftChild :			(( elements[ leftChild ] > elements[ rightChild ] )? leftChild : rightChild );			if ( elements[ largest ] > temp ) {			elements[ i ] = elements[ largest ];			i = largest;			leftChild = (i << 1) + 1;			}		else			stop = true;		}	elements[ i ] = temp;}