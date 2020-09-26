#include <iostream>
using namespace std;

// minheap implementation of array
void minheap(int arr[], int i, int n)
{
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;
    int s = i;
    if (l < n && arr[l] < arr[s])
    {
        s = l;
    }
    if (r < n && arr[r] < arr[s])
    {
        s = r;
    }
    if (s != i)
    {
        swap(arr[i], arr[s]);
        minheap(arr, s, n); // again checking if swapped value satisfies minheap condition
    }
}


int main()
{
    int n;
    cout << "enter no of elements of array" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter element" << i + 1 << endl;
        cin >> arr[i];
    }
    // n/2 is the first leaf node; n/2-1 is the last non leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minheap(arr, i, n); // checking for all non-leafnode starting from the end
    }

    cout << "Min Heap" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}