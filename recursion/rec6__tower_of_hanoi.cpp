#include <iostream>
using namespace std;

void toh(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) // end condition
    {
        cout << "Move disk 1 from rod " << from_rod << " from rod " << to_rod << endl;
        return;
    }
    else
    {
        toh(n-1, from_rod, aux_rod, to_rod);
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        toh(n-1, aux_rod, to_rod, from_rod);
    }
}

int main()
{
    int n = 5;
    toh(n, 'A', 'B', 'C');

    return 0;
}