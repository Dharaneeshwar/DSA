
/*
Here is an array of pile of chocolates.
In every iteration a person chose a pile with the maximum number of chocolates after that square root of chocolate remains and rest is eaten by him.
After k iterations find the number of chocolates remaining.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // getting inputs
    int n;
    cin >> n;
    int a[n];
    int k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> k;
    
    
    for (int i = 0; i < k; i++)
    {
        *max_element(a, a + n) = sqrt(*max_element(a, a + n));
        // finds the max element, substitutes the square root of the number
    }
    
    cout << accumulate(a, a + n, 0); // sum of arr of n numbers; syntax -> accumulate(start,end,initial_sum);  
    
    return 0;
}