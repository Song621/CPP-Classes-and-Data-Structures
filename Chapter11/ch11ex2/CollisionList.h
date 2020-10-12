#pragma once
#include <iostream>

template <class DataType>
struct Node {
    DataType info;
    Node<DataType>* next{};
    Node<DataType>* dlnext{};
    Node<DataType>* dlback{};
};

template <class DataType>
class CollisionList
{
public:
    CollisionList();
    CollisionList(const CollisionList<DataType>& aplist);
    ~CollisionList();
    CollisionList<DataType>& operator = (const CollisionList<DataType>& rlist);
    void insert(const DataType& element);
    bool first(DataType& listEl);
    inline bool getNext(DataType& listEl);
    bool find(const DataType& element);
    bool retrieve(DataType& element);
    bool replace(const DataType& newElement);
    bool remove(const DataType& element);
    bool isEmpty() const;
    void makeEmpty();
    Node<DataType>* getcurrent();
private:
    Node<DataType>* start;
    Node<DataType>* current;
    inline void deepCopy(const CollisionList<DataType>& original);
};

template <class DataType>
CollisionList<DataType>::CollisionList()
{
    start = current = NULL;
}

template <class DataType>
CollisionList<DataType>::CollisionList(const CollisionList<DataType>& aplist)
{
    deepCopy(aplist);
}

template <class DataType>
CollisionList<DataType>::~CollisionList()
{
    makeEmpty();
}

template <class DataType>
CollisionList<DataType>& CollisionList<DataType>::operator=(const CollisionList<DataType>& rlist)
{
    if (this == &rlist)
        return *this;
    makeEmpty();
    deepCopy(rlist);
    return *this;
}

template <class DataType>
void CollisionList<DataType>::insert(const DataType& element)
{
    //current = NULL;
    Node<DataType>* newNode = new Node<DataType>;
    newNode->info = element;
    newNode->next = start;
    current = start = newNode;
}

template <class DataType>
bool CollisionList<DataType>::first(DataType& listEl)
{
    if (start == NULL)
        return false;

    current = start;
    listEl = start->info;
    return true;
}

template <class DataType>
inline bool CollisionList<DataType>::getNext(DataType& listEl)
{
    if (current == NULL)
        return false;
    if (current->next == NULL) {
        current = NULL;
        return false;
    }

    current = current->next;
    listEl = current->info;
    return true;
}

template <class DataType>
bool CollisionList<DataType>::find(const DataType& element)
{
    DataType item;
    if (!first(item))
        return false;
    do if (item == element)
        return true;
    while (getNext(item));

    return false;
}

template <class DataType>
bool CollisionList<DataType>::retrieve(DataType& element)
{
    if (!find(element))
        return false;

    element = current->info;
    return true;
}

template <class DataType>
bool CollisionList<DataType>::replace(const DataType& newElement)
{
    if (current == NULL)
        return false;
    current->info = newElement;
    return true;
}

template <class DataType>
bool CollisionList<DataType>::remove(const DataType& element)
{
    current = NULL;
    if (start == NULL)
        return false;
    Node<DataType>* ptr = start;
    if (ptr->info == element) {
        element = ptr->info;
        start = start->next;
        delete ptr;
        return true;
    }
    while (ptr->next != NULL) {
        if (ptr->next->info == element) {
            Node<DataType>* tempPtr = ptr->next;
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
bool CollisionList<DataType>::isEmpty() const
{
    return start == NULL;
}

template <class DataType>
void CollisionList<DataType>::makeEmpty()
{
    while (start != NULL) {
        current = start;
        start = start->next;
        delete current;
    }

    current = NULL;
}

template<class DataType>
Node<DataType>* CollisionList<DataType>::getcurrent()
{
    return current;
}

template <class DataType>
inline void CollisionList<DataType>::deepCopy(const CollisionList<DataType>& origianl)
{
    start = current = NULL;
    if (origianl.start == NULL)
        return;
    Node<DataType>* copyptr = start = new Node<DataType>;
    Node<DataType>* originalptr = origianl.start;
    copyptr->info = originalptr->info;
    if (originalptr == origianl.current)
        current = copyptr;
    while (originalptr->next != NULL) {
        originalptr = originalptr->next;
        copyptr->next = new Node<DataType>;
        copyptr = copyptr->next;
        copyptr->info = originalptr->info;
        if (originalptr == origianl.current)
            current = copyptr;
    }

    copyptr->next = NULL;
}