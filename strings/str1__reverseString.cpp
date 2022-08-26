#include <iostream>
#include <string>
using namespace std;

string revString(string s)
{
    int rev_i = 0;
    string reversed="";

    for (int i = 0; i < s.length(); i++)
    {
        rev_i = (s.length() - 1) - i;
        reversed += s[rev_i];
    }

    return reversed; 
}

int main()
{
    string s;

    cout << "Enter the string you wanna have reversed: " << endl;
    cin >> s;
    cout << "sizeof(string): " << sizeof(s) << endl;
    cout << "lengthof(string): " << s.length() << endl;

    cout << "The desired reversed string: " << revString(s) << endl;

    return 0;
}