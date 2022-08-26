#include<iostream>
#include<string>
using namespace std;

// WAP which takes string input and returns character count

void returnCharCount(string s)
{   
    for(int i=0; i < s.length(); i++)
    {
        char occurence = s[i];
        int count = 1;
        for(int j=i+1; j < s.length(); j++)
        {
            if (occurence == s[j])
            {
                count +=1;
            }
        }
        cout << "The character " << occurence << " occured " << count << " times in string " << s << " !" << endl;
    }
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    returnCharCount(str);
    return 0;
}