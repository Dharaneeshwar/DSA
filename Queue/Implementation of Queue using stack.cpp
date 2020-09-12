#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, v;
    cout << "Enter the size of stack:" << endl;
    cin >> n;
    cout << "Enter the stack values:" << endl;
    // declare two stacks
    stack<int> st;
    stack<int> st1;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        st.push(v);
    }
    while (st.empty() == false)
    {
        int t = st.top();
        st1.push(t);
        st.pop();
    }
    cout << "Queue elements are:" << endl;
    if (n <= 0)
    {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    while (st1.empty() == false)
    {
        int t = st1.top();
        cout << t << " ";
        st1.pop();
    }
    return 0;
}