#pragma once

#include "DLHashTable.h"

template <class DataType>
class DoublyLinkedList
{
public:
	DoublyLinkedList(int (*hf)(const DataType &), int s);
	DoublyLinkedList(const DoublyLinkedList<DataType>& aplist);
	~DoublyLinkedList();
	DoublyLinkedList<DataType>& operator =(const DoublyLinkedList<DataType>& rlist);
	bool insert(const DataType& element);
	bool first(DataType& listEl);
	inline bool getNext(DataType& listEl);
	bool last(DataType& listEl);
	inline bool getPrevious(DataType& listEl);
	bool find(const DataType& element);
	bool retrieve(DataType& element);
	bool remove(DataType& element);
	bool replace(const DataType& newElement);
	bool isEmpty() const;
	void makeEmpty();
private:
	DLHashTable<DataType> table;
	Node<DataType>* current;
	Node<DataType> headerNode;
	Node<DataType> trailerNode;
	Node<DataType>* header;
	Node<DataType>* trailer;
	inline void deepCopy(const DoublyLinkedList<DataType>& original);
};

template<class DataType>
DoublyLinkedList<DataType>::DoublyLinkedList(int(*hf)(const DataType&), int s)
	:table(hf, s), header(&headerNode), trailer(&trailerNode)
{
	current = header->dlnext = trailer;
	trailer->dlback = header;
}

template <class DataType>
DoublyLinkedList<DataType>::DoublyLinkedList(const DoublyLinkedList<DataType>& aplist)
	:table(aplist.table.gethashfunc(), aplist.table.getsize())
{
	deepCopy();
}

template <class DataType>
DoublyLinkedList<DataType>::~DoublyLinkedList()
{
	makeEmpty();
}

template <class DataType>
DoublyLinkedList<DataType>& DoublyLinkedList<DataType>::operator=(const DoublyLinkedList<DataType>& rlist)
{
	if (this == rlist)
		return *this;
	makeEmpty();
	deepCopy(rlist);
	return *this;
}

template <class DataType>
bool DoublyLinkedList<DataType>::insert(const DataType& element)
{
	if (!table.insert(element))
		return false;
	
	current = table.getcurrent();
	current->dlnext = header->dlnext;
	current->dlback = header;
	header->dlnext = header->dlnext->dlback = current;
	current = trailer;

	return true;
}

template <class DataType>
bool DoublyLinkedList<DataType>::first(DataType& listEl)
{
	if (header->dlnext == trailer)
		return false;

	current = header->dlnext;
	listEl = current->info;
	return listEl;
}

template <class DataType>
inline bool DoublyLinkedList<DataType>::getNext(DataType& listEl)
{
	if (header->dlnext == trailer)
		return false;
	if (current->dlnext == trailer)
		return false;

	current = current->dlnext;
	listEl = current->info;
	return true;
}

template <class DataType>
bool DoublyLinkedList<DataType>::last(DataType& listEl)
{
	if (header->dlnext == trailer)
		return false;
	current = trailer->dlback;
	listEl = current->info;
	return true;
}

template <class DataType>
inline bool DoublyLinkedList<DataType>::getPrevious(DataType& listEl)
{
	if (current->dlback == header)
		current = trailer;
	if (current == trailer)
		return false;

	current = current->dlback;
	listEl = current->info;
	return true;
}

template <class DataType>
bool DoublyLinkedList<DataType>::find(const DataType& element)
{
	DataType e1 = element;
	if (table.retrieve(e1)) {
		current = table.getcurrent();
		return true;
	}

	current = trailer;
	return false;
}

template <class DataType>
bool DoublyLinkedList<DataType>::retrieve(DataType& element)
{
	if (!find(element))
		return false;

	element = current->info;
	return true;
}

template <class DataType>
bool DoublyLinkedList<DataType>::remove(DataType& element)
{
	if (!retrieve(element))
		return false;

	current->dlback->dlnext = current->dlnext;
	current->dlnext->dlback = current->dlback;
	current = trailer;
	table.remove(element);

	return true;
}

template <class DataType>
bool DoublyLinkedList<DataType>::replace(const DataType& newElement)
{
	if (current == trailer)
		return false;

	current->info = newElement;
	return true;
}

template <class DataType>
bool DoublyLinkedList<DataType>::isEmpty() const
{
	return header->dlback == trailer;
}

template <class DataType>
void DoublyLinkedList<DataType>::makeEmpty()
{
	table.makeEmpty();
	current = header->dlnext = trailer;
	trailer->dlback = header;
}

template <class DataType>
inline void DoublyLinkedList<DataType>::deepCopy(const DoublyLinkedList<DataType>& original)
{
	if (table.getsize() != original.table.getsize())
		table.changeSize(original.table.getsize());
	table.sethashfunc(original.table.gethashfunc());
	header = &header;
	trailer = &trailerNode;
	Node<DataType>* save = header->dlnext = trailer;
	trailer->dlback = header;
	Node<DataType>* originalptr = original.trailer->dlback;
	if (originalptr == original.header || !insert(originalptr->info))
		return;
	while (originalptr->dlback != header) {
		originalptr = originalptr->dlback;
		if (!insert(originalptr->info)) {
			makeEmpty();
			return;
		}
		if (original.current == originalptr)
			save = header->dlnext;
	}
	current = save;
}