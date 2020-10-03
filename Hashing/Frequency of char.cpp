#include <iostream>
#include <string>
using namespace std;

int main()
{
    int asc[26] = {0};
    string a;
    cin >> a; // inputs a string
    for (char ch : a)
    {
        asc[ch - 97] += 1; // ch is implicitly typecasted to int (ascii) and -97 will accomodate the alphabetetical range within arr of size 26
    }
    for (int i = 0; i < 26; i++)
    {
        if (asc[i] > 0)
        {
            cout << (char)(i + 97) << ":" << asc[i] << endl; // converting index back to char by +97 (explicit typecast)
        }
    }
    return 0;
}