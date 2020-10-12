#pragma once
#include "Array.h"
#include "LinkedList.h"

template <class DataType>
class HashTable
{
public:
    HashTable(int (*hf)(const DataType &),int s);
    bool insert(const DataType & newObject);
    bool retrieve(DataType & retrieved);
    bool remove(DataType & removed);
    bool update(DataType & updateObject);
    void makeEmpty();
private:
    Array<LinkedList<DataType> > table;
    int (*hashfunc) (const DataType &);
};

template <class DataType>
HashTable<DataType>::HashTable(int (*hf)(const DataType &),int s)
    :table(s)
{
    hashfunc = hf;
}

template <class DataType>
bool HashTable<DataType>::insert(const DataType & newObject)
{
    int location = hashfunc(newObject);
    if(location < 0 || location >= table.length())
        return false;
    table[location].insert(newObject);
	return true;
}

template <class DataType>
bool HashTable<DataType>::retrieve(DataType & retrieved)
{
    int location = hashfunc(retrieved);
    if(location < 0 || location >= table.length())
        return false;
    return table[location].retrieve(retrieved);    
}

template <class DataType>
bool HashTable<DataType>::remove(DataType & removed)
{
    int location = hashfunc(removed);
    if(location < 0 || location >= table.length())
        return false;
    return table[location].remove(removed);
}

template <class DataType>
bool HashTable<DataType>::update(DataType & updateObject)
{
    int location = hashfunc(updateObject);
    if(location < 0 || location >= table.length())
        return false;
    if(!table[location].find(updateObject))//updateObject应该是之前没有的，找不到应该，这里有问题
        return false;
    table[location].replace(updateObject);
    return true;   
}

template <class DataType>
void HashTable<DataType>::makeEmpty()
{
    for (int i = 0; i < table.length(); i++)
        table[i].makeEmpty();
}