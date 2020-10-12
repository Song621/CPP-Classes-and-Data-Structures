#pragma once
#include "Array.h"
#include "CollisionList.h"

template <class DataType>
class DLHashTable
{
public:
	DLHashTable(int (*hf)(const DataType&), int s);
	bool insert(const DataType& newObject);
	bool retrieve(DataType& retrieved);
	bool remove(DataType& removed);
	bool update(DataType& updateObject);
	void makeEmpty();
	Node<DataType>* getcurrent();
	int (*gethashfunc() const)(const DataType&);
	void sethashfunc(int (*hf)(const DataType&));
	int getsize() const;
	void changeSize(int newSize);
private:
	Array<CollisionList<DataType> > table;
	int (*hashfunc)(const DataType&);
	int location;
};

template <class DataType>
DLHashTable<DataType>::DLHashTable(int(*hf)(const DataType&), int s)
	:table(s)
{
	hashfunc = hf;
}

template <class DataType>
bool DLHashTable<DataType>::insert(const DataType& newObject)
{
	location = hashfunc(newObject);
	if (location < 0 || location > table.length())
		return false;
	table[location].insert(newObject);
	return true;
}

template <class DataType>
bool DLHashTable<DataType>::retrieve(DataType& retrieved)
{
	location = hashfunc(retrieved);
	if (location < 0 || location > table.length())
		return false;
	if (!table[location].retrieve(retrieved))
		return false;
	return true;
}

template <class DataType>
bool DLHashTable<DataType>::remove(DataType& removed)
{
	location = hashfunc(removed);
	if (location < 0 || location > table.length())
		return false;
	if (!table[location].remove(removed))
		return false;
	return true;
}

template <class DataType>
bool DLHashTable<DataType>::update(DataType& updateObject)
{
	location = hashfunc(updateObject);
	if (location < 0 || location > table.length())
		return false;
	if (!table[location].find(updateObject))
		return false;
	table[location].replace(updateObject);
	return true;
}

template <class DataType>
void DLHashTable<DataType>::makeEmpty()
{
	for (int i = 0; i < table.length(); i++)
		table[i].makeEmpty();
}

template <class DataType>
Node<DataType>* DLHashTable<DataType>::getcurrent()
{
	return table[location].getcurrent();
}

template <class DataType>
int (*DLHashTable<DataType>::gethashfunc() const)(const DataType&)
{
	return hashfunc;
}

template <class DataType>
void DLHashTable<DataType>::sethashfunc(int (*hf)(const DataType&))
{
	hashfunc = hf;
}

template <class DataType>
int DLHashTable<DataType>::getsize() const
{
	return table.length();
}

template <class DataType>
void DLHashTable<DataType>::changeSize(int newSize)
{
	table.changeSize(newSize);
}