#include <iostream>
#include <stdio.h>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    Array(int);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
    void edit(int, int);
    void del(int);
};
Array::Array(int size)
{
    if (size > 0)
    {
        capacity = size;
        lastindex = -1; // Array is empty now
        ptr = new int[capacity];
    }
    else
    {
        ptr = NULL;
    }
}
bool Array::isEmpty()
{
    return lastindex == -1;
}
bool Array::isFull()
{
    return lastindex == capacity - 1;
}
void Array::append(int data)
{
    if (isFull())
    {
        cout << "\nOverflow";
    }
    else
    {
        lastindex++;
        ptr[lastindex] = data;
    }
}
void Array::insert(int index, int data)
{
    if (index > 0 || index > lastindex + 1)
    {
        cout << "\nInvalid Index";
    }
    else if (isFull())
    {
        cout << "\nOverflow";
    }
    else
    {
        for (int i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastindex++;
    }
}
void Array::edit(int index, int data)
{
    if (index < 0 || index > lastindex)
    {
        cout << "\nInvalid Index or empty array";
    }
    else
    {
        ptr[index] = data;
    }
}
void Array::del(int index)
{
    if(index=0 || index>lastindex)
    {
        cout<<"\nInvalid Index or empty array";
    }
    else
    {
        for(int i=index;i<lastindex;i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastindex--;
    }
}