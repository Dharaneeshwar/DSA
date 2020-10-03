#include <iostream>
#include <algorithm>
using namespace std;

int binarysearch(int arr[], int start, int end, int key)
{
    if (end < start)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else
    {
        if (arr[mid] > key)
        {
            binarysearch(arr, start, mid - 1, key);
        }
        else
        {
            binarysearch(arr, mid + 1, end, key);
        }
    }
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    sort(arr,arr+n);
    int key = binarysearch(arr, 0, n - 1, k);
    if (key == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << k << " found at location " << key + 1 << ".";
    }
    return 0;
}