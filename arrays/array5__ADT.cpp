#include <iostream>
using namespace std;

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
};

// *a is the pointer that points to the first element of the array
myArr::myArr(myArr *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int(tSize * sizeof(int));
}

void myArr::display(myArr *a)
{
    cout << "The elements your array containing are: " << endl;
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

int main()
{
    myArr marks(&marks, 10, 6);
    cout << marks.total_size << endl;
    cout << marks.used_size << endl;

    marks.setVal(&marks);
    marks.display(&marks);
    marks.display_address(&marks);

    return 0;
}