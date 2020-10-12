// DoublyLinkedList.cpp -- function definitions for the linked list data structure

template <class DataType>
DoublyLinkedList<DataType>::DoublyLinkedList(int (*hf)(const DataType &), int s )
: table( hf, s ), header( &headerNode ), trailer( &trailerNode )
{
	current = header->dlnext = trailer;
	trailer->dlback = header;
}

template <class DataType>
DoublyLinkedList<DataType>::DoublyLinkedList( const DoublyLinkedList<DataType> & aplist )
: table( aplist.table.gethashfunc( ), aplist.table.getsize( ) )
{
	deepCopy( aplist );
}

template <class DataType>
DoublyLinkedList<DataType>::~DoublyLinkedList( )
{
	makeEmpty( );
}

template <class DataType>
DoublyLinkedList<DataType> & DoublyLinkedList<DataType>::operator =( 
									const DoublyLinkedList<DataType> & rlist )
{
	if ( this == &rlist )
		return *this;
	makeEmpty( );
	deepCopy( rlist );
	return *this;
}

// inserts at the beginning of the linked list
// no current position after use		
template <class DataType>
bool DoublyLinkedList<DataType>::insert( const DataType & element )
{
	if ( !table.insert( element ) )
		return false;

	current = table.getcurrent( );
	current->dlnext = header->dlnext;
	current->dlback = header;
	header->dlnext = header->dlnext->dlback = current;
	current = trailer;

	return true;
}	

// returns first element of list in listEl and current position is set to this element; 
// if list is empty, returns false and there is no current position; 
// otherwise, returns true
template <class DataType>
bool DoublyLinkedList<DataType>::first( DataType & listEl )
{
	if ( header->dlnext == trailer ) 
		return false;

	current = header->dlnext;
	listEl = current->info;
	return true;
}


// retrieves the next element of a linked list beyond the last element that was retrieved
// by first, getNext, or getPrevious functions and returns it in listEl;
// current position is set to this element.
// if no element exists at this position, getNext returns false and there is no 
// current position; returns true otherwise	
template <class DataType>
inline bool DoublyLinkedList<DataType>::getNext( DataType & listEl )				  
{
	if ( current->dlnext == trailer )
		current = trailer;
	if ( current == trailer ) 
		return false;

	current = current->dlnext;
	listEl = current->info;
	return true;
}

// returns last element of list in listEl and current position is set to this element; 
// if list is empty, returns false and there is no current position; 
// otherwise, returns true
template <class DataType>
bool DoublyLinkedList<DataType>::last( DataType & listEl )
{
	if ( header->dlnext == trailer ) 
		return false;

	current = trailer->dlback;
	listEl = current->info;
	return true;
}


// retrieves the previous element of a linked list before the last element that was 
// retrieved by last, getNext or getPrevious functions and returns it in listEl;
// current position is set to this element.
// if no element exists at this position, getPrevious returns false and there is no 
// current position; returns true otherwise	
template <class DataType>
inline bool DoublyLinkedList<DataType>::getPrevious( DataType & listEl )				  
{
	if ( current->dlback == header )
		current = trailer;
	if ( current == trailer )
		return false;

	current = current->dlback;
	listEl = current->info;
	return true;
}


// returns true if element is found; returns false if element is not found
// if found, found element becomes current position in list; 
// if not found, there is no current position
template <class DataType>
bool DoublyLinkedList<DataType>::find( const DataType & element )
{
	DataType el = element;
	if ( table.retrieve( el ) ) {
		current = table.getcurrent( );
		return true;
	}

	current = trailer;
	return false;
}

// returns true if element is found; returns false if element is not found
// if found, found element becomes current position in list; 
// if not found, there is no current position
template <class DataType>
bool DoublyLinkedList<DataType>::retrieve( DataType & element )
{
	if ( !find( element ) )
		return false;

	element = current->info;
	return true;
}

// returns true if element is found; returns false if element is not found
// if found, element is set to found element;
// no current position after use
template <class DataType>
bool DoublyLinkedList<DataType>::remove( DataType & element )
{
	if ( !retrieve( element ) )
		return false;
	current->dlback->dlnext = current->dlnext;
	current->dlnext->dlback = current->dlback;
	current = trailer;
	table.remove( element );

	return true;
}


// replaces element at current position in list with newElement; 
// returns false if there is no current position (no list modification occurs); 
// returns true otherwise 
template <class DataType>
bool DoublyLinkedList<DataType>::replace( const DataType & newElement ) 
{
	if ( current == trailer )
		return false;
	current->info = newElement;
	return true;
}


template <class DataType>
bool DoublyLinkedList<DataType>::isEmpty( ) const				  
{
	return header->dlnext == trailer;
}

template <class DataType>
void DoublyLinkedList<DataType>::makeEmpty( )					  
{
	table.makeEmpty( );
	current = header->dlnext = trailer;
	trailer->dlback = header;
}

template <class DataType>
inline void DoublyLinkedList<DataType>::deepCopy( const DoublyLinkedList<DataType> & original )
{
	if ( original.table.getsize( ) != table.getsize( ) )
		table.changeSize( original.table.getsize( ) );
	table.sethashfunc( original.table.gethashfunc( ) );
	header = &headerNode;
	trailer = &trailerNode;
	Node<DataType> *save = header->dlnext = trailer;
	trailer->dlback = header;
	Node<DataType> *originalptr = original.trailer->dlback;
	if ( (originalptr == original.header) || !insert( originalptr->info ) )
		return;
	while ( originalptr->dlback != original.header ) {
		originalptr = originalptr->dlback;
		if ( !insert( originalptr->info ) ) {
			makeEmpty( );
			return;
		}
		if ( original.current == originalptr )
			save = header->dlnext;
	}

	current = save;
}
