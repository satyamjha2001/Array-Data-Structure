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
    return lastindex==-1;
}
bool Array::isFull()
{
    return lastindex==capacity-1;
}
void Array::append(int data)
{
    if(isFull())
    {
        cout<<"\nOverflow";
    }
    else
    {
        lastindex++;
        ptr[lastindex]=data;
    }
}
