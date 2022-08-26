#include <iostream>
using namespace std;

//*********************** Recursion *****************************************
/* Recursion is the process in which function calls itself with a failure condition.
That's it! that's all there is to it.
*/

// Tail/Bottom Recursive function
void f_head(int n)
{
    if (n > 0)
    {
        f_head(n - 1);
        cout << "Black Clover chapter: " << n << endl;
    }
}

// Tail/Bottom Recursive function
void f_tail(int n)
{
    if (n > 0)
    {
        f_tail(n - 1);
        cout << "Black Clover chapter: " << n << endl;
    }
}

// Tree Recursive function
void f_tree(int n)
{
    if (n > 0)
    {
        cout << "Black Clover chapter: " << n << endl;
        f_tree(n - 1);
        f_tree(n - 1);
    }
}

// Tree Recursive function, variation I
void f_tree1(int n)
{
    if (n > 0)
    {
        f_tree1(n - 1);
        f_tree1(n - 1);
        cout << "Black Clover chapter: " << n << endl;
    }
}

// Tree Recursive function, variation II
void f_tree2(int n)
{
    if (n > 0)
    {
        f_tree2(n - 1);
        cout << "Black Clover chapter: " << n << endl;
        f_tree2(n - 1);
    }
}

int main()
{
    // f_head(3);
    // f_tail(170);
    // f_tree(3);
    // f_tree1(3);
    f_tree2(3);

    return 0;
}