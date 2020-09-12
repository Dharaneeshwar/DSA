#include <iostream>
using namespace std;
int queue[100], front = -1, rear = -1;
void insert(int val)
{
    if (front == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else
    {
        queue[++rear] = val;
    }
}
void delete_ele()
{
    if (front == -1 || front > rear)
        cout << "Queue underflow";
    else
        front++;
}
int main()
{
    int n, value;
    cin >> n;                   //5
    for (int i = 0; i < n; i++) //i=5; 5<5 false
    {
        cout << "Insert the element in queue :" << endl;
        cin >> value; //1 2 3 4 5
        insert(value);
    }
    if (front == -1)
        cout << "Queue is empty";
    else
    {
        cout << "Queue elements are :" << endl;
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    }
    return 0;
}