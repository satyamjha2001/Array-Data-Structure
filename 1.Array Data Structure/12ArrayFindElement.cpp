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
    int getItem(int);
    int count();
    int find(int);
    ~Array();
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
    if (index < 0 || index > lastindex + 1)
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
    if(index<0 || index>lastindex)
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
int Array::getItem(int index)
{
    if(index<0||index>lastindex)
    {
        cout<<"\nInvalid Index or Empty Array";
        throw new exception();
    }
    return ptr[index];
}
int Array::count()
{
    return lastindex+1;
}
Array::~Array()
{
    delete []ptr;
}
int Array::find(int data)
{
    for(int i=0;i<=lastindex;i++)
    {
        if(ptr[i]==data)
        {
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Array arr(size);

    // int data;

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Enter value " << i + 1 << ": ";
    //     cin >> data;
    //     arr.append(data);
    // }

    // cout << "Array after inserting 5 values: ";
    // for (int i = 0; i < arr.count(); i++)
    // {
    //     cout << arr.getItem(i) << " ";
    // }
    // cout << endl;

    int choice, data, index;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Append\n";
        cout << "2. Insert\n";
        cout << "3. Edit\n";
        cout << "4. Delete\n";
        cout << "5. Get Item\n";
        cout << "6. Count\n";
        cout << "7. Find\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to append: ";
            cin >> data;
            arr.append(data);
            break;

        case 2:
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter data to insert: ";
            cin >> data;
            arr.insert(index, data);
            break;

        case 3:
            cout << "Enter index to edit: ";
            cin >> index;
            cout << "Enter new data: ";
            cin >> data;
            arr.edit(index, data);
            break;

        case 4:
            cout << "Enter index to delete: ";
            cin >> index;
            arr.del(index);
            break;

        case 5:
            cout << "Enter index to get item from: ";
            cin >> index;
            try
            {
                int item = arr.getItem(index);
                cout << "Item at index " << index << ": " << item << endl;
            }
            catch (exception &e)
            {
                // Handle exception here
                cout << e.what() << endl;
            }
            break;

        case 6:
            cout << "Number of elements in the array: " << arr.count() << endl;
            break;

        case 7:
            cout << "Enter data to find: ";
            cin >> data;
            index = arr.find(data);
            if (index != -1)
            {
                cout << "Data found at index: " << index << endl;
            }
            else
            {
                cout << "Data not found in the array." << endl;
            }
            break;

        case 8:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}
