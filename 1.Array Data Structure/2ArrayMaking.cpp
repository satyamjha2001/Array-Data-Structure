#include <iostream>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;
    Array(int);
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