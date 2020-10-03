#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, substr;
    getline(cin, str);
    cin >> substr;
    for (int i = 0; i < str.length() - substr.length() + 1; i++)
    {
        int count = 0;
        for (int j = 0; j < substr.length(); j++)
        {
            if (str[i + j] == substr[j])
            {
                count += 1;
            }
        }
        if (count == substr.length())
        {
            cout << "Pattern found at index " << i;
        }
    }
    return 0;
}