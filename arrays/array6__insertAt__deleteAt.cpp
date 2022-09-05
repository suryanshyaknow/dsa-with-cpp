#include <iostream>
using namespace std;

// Following operations are supported by an array:
/*
--> Traversal
--> Insertion
--> Deletion
--> Search
*/
// ************************************ Insertion: *******************************************************
// ************************************ Deletion:  *******************************************************

class myArr
{
public:
    /* data */
    int total_size;
    int used_size;
    int *ptr; // needed to request desired memory in heap

    myArr(myArr *a, int tSize, int uSize);
    void display(myArr *);
    void display_address(myArr *);
    void setVal(myArr *);
    int insertAt(myArr *, int, int);
    int deleteAt(myArr *, int);
};

// *a is the pointer that points to the first element of the array
myArr::myArr(myArr *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int(tSize * sizeof(int)); // memory request from heap
}

void myArr::display(myArr *a)
{
    cout << "The elements your array's containing are: " << endl;
    for (int i = 0; i < a->used_size; i++)
    {
        /* code */
        cout << a->ptr[i] << " ";
    }
    cout << endl;
}

void myArr::display_address(myArr *a)
{
    cout << "The adrresses accupied in the heap by the pointer are: " << endl;
    for (int i = 0; i < a->used_size; i++)
    {
        /* code */
        cout << a->ptr << " ";
        ptr++;
    }
    cout << endl;
}

void myArr::setVal(myArr *a)
{
    cout << "Start entering elements into the array from here on: " << endl;
    for (int i = 0; i < a->used_size; i++)
    {
        /* code */
        cin >> a->ptr[i];
    }
}

int myArr::insertAt(myArr *a, int at, int insertion)
{
    // can't allow insertion if it's beyond the scope of the total size
    if (at >= a->total_size)
    {
        return -1;
    }
    // insertion
    for (int i = a->used_size - 1; i > at; i--)
    {
        /* code */
        a->ptr[i + 1] = a->ptr[i];
    }
    a->ptr[at] = insertion;
    a->used_size += 1;
    return 1;
}

int myArr::deleteAt(myArr *a, int at)
{
    if (at >= a->used_size || at >= a->total_size)
    {
        cout << "..beyond the scope of the size of the array!" << endl;
        return -1;
    }
    for (int i = at; i <= a->used_size; i++)
    {
        /* code */
        a->ptr[i] = a->ptr[i + 1];
    }
    a->used_size -= 1;
    return 1;
}

int main()
{
    myArr marks(&marks, 10, 6);
    cout << "marks.total_size: " << marks.total_size << endl;
    cout << "marks.used_size: " << marks.used_size << endl;

    marks.setVal(&marks);
    marks.display(&marks);
    // marks.display_address(&marks);
    // --> Can't use the above method carelessly because it organically changes the pointer's location.

    // Insertion:
    // marks.insertAt(&marks, 4, 1972);
    // cout << "\nDisplaying the array after insertion: ";
    // marks.display(&marks);

    // Deletion:
    // marks.deleteAt(&marks, marks.used_size - 4);
    marks.deleteAt(&marks, 0);
    cout << "\nAfter deletion: " << endl;
    marks.display(&marks);

    return 0;
}