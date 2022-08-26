#include <iostream>
#include <string>
using namespace std;

class RevString
{
    string str;
    void swap(char &, char &); // declaring private function
    void reverse();            // will genetically modfiy the string

public:
    RevString();         // default constructor
    RevString(string &); // parameterized constructor
};

RevString::RevString()
{
    cout << "Since no string was passed as an argument to be reversed, we'll provide default one\ 
from our side to demonstrate our functioning."
         << endl;

    str = "default_string";
    reverse();
}

RevString::RevString(string &s)
{
    str = s;
    reverse();
}

void RevString::swap(char &c1, char &c2)
{
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

void RevString::reverse()
{
    cout << "Before Revrsing string was as: " << str << endl;

    for (int i = 0; i < str.length() / 2; i++)
    {
        swap(str[i], str[(str.length() - 1) - i]);
    }

    cout << "Reveresed string: " << str << endl;
}

int main()
{
    RevString rev;

    string s;
    cout << "Enter the string you wanna have reversed: " << endl;
    cin >> s;
    RevString reverse(s);

    return 0;
}