#pragma once
#include <iostream>

template <class DataType>
struct Node{
    DataType info;
    Node<DataType>* next{};
};

template <class DataType>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<DataType> & aplist);
    ~LinkedList();
    LinkedList<DataType> & operator = (const LinkedList<DataType> & rlist);
    void insert(const DataType & element);
    bool first(DataType & listEl);
    inline bool getNext(DataType & listEl);
    bool find(const DataType & element);
    bool retrieve(DataType & element);
    bool replace(const DataType & newElement);
    bool remove(DataType & element);
    bool isEmpty() const;
    void makeEmpty();
private:
    Node<DataType> *start;
    Node<DataType> *current;
    inline void deepCopy(const LinkedList<DataType> & original);
};

template <class DataType>
LinkedList<DataType>::LinkedList()
{
    start = current = NULL;
}

template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType> & aplist)
{
    deepCopy(aplist);
}

template <class DataType>
LinkedList<DataType>::~LinkedList()
{
    makeEmpty();
}

template <class DataType>
LinkedList<DataType> & LinkedList<DataType>::operator=(const LinkedList<DataType> & rlist)
{
    if(this == &rlist)
        return *this;
    makeEmpty();
    deepCopy(rlist);
    return *this;
}

template <class DataType>
void LinkedList<DataType>::insert(const DataType & element)
{
    current = NULL;
    Node<DataType> *newNode = new Node<DataType>;
    newNode->info = element;
    newNode->next = start;
    start = newNode;
}

template <class DataType>
bool LinkedList<DataType>::first(DataType & listEl)
{
    if(start == NULL)
        return false;
    
    current = start;
    listEl = start->info;
    return true;
}

template <class DataType>
inline bool LinkedList<DataType>::getNext(DataType & listEl)
{
    if(current == NULL)
        return false;
    if(current->next == NULL){
        current = NULL;
        return false;
    }

    current = current->next;
    listEl = current->info;
    return true;
}

template <class DataType>
bool LinkedList<DataType>::find(const DataType & element)
{
    DataType item;
    if(!first(item))
        return false;
    do if(item == element)
        return true;
    while(getNext(item));

    return false;
}

template <class DataType>
bool LinkedList<DataType>::retrieve(DataType & element)
{
    if(!find(element))
        return false;
    
    element = current->info;
    return true;
}

template <class DataType>
bool LinkedList<DataType>::replace(const DataType & newElement)
{
    if(current == NULL)
        return false;
    current->info = newElement;
    return true;
}

template <class DataType>
bool LinkedList<DataType>::remove(DataType & element)
{
    current = NULL;
    if(start == NULL)
        return false;
    Node<DataType> *ptr = start;
    if(ptr->info == element){
		element = ptr->info;
        start = start->next;
        delete ptr;
        return true;
    }
    while(ptr->next != NULL){
        if(ptr->next->info == element){
            Node<DataType> *tempPtr = ptr->next;
			element = tempPtr->info;
            ptr->next = tempPtr->next;
            delete tempPtr;
            return true;
        }
		ptr = ptr->next;
    }
	
    return false;
}

template <class DataType>
bool LinkedList<DataType>::isEmpty() const
{
    return start == NULL;
}

template <class DataType>
void LinkedList<DataType>::makeEmpty()
{
    while(start != NULL){
        current = start;
        start = start->next;
        delete current;
    }

    current = NULL;
}

template <class DataType>
inline void LinkedList<DataType>::deepCopy(const LinkedList<DataType> & origianl)
{
    start = current = NULL;
    if(origianl.start == NULL)
        return;
    Node<DataType> *copyptr = start = new Node<DataType>;
    Node<DataType> *originalptr = origianl.start;
    copyptr->info = originalptr->info;
    if(originalptr == origianl.current)
        current = copyptr;
    while(originalptr->next != NULL){
        originalptr = originalptr->next;
        copyptr->next = new Node<DataType>;
        copyptr = copyptr->next;
        copyptr->info = originalptr->info;
        if(originalptr == origianl.current)
            current = copyptr;
    }

    copyptr->next = NULL;
}