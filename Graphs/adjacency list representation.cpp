#include <iostream>
#include <list>
using namespace std;
int main()
{
    int nv, ne;
    cout << "Enter the number of vertices:" << endl;
    cout << "Enter the number of edges:" << endl;
    cin >> nv >> ne; // number of vertex and edge
    list<int> l[nv];
    int s, e;
    for (int i = 0; i < ne; i++)
    {
        cout << "Enter the Start node and End node of edge " << i + 1 << endl;
        cin >> s >> e;
        l[s].push_back(e);  // adding the edge to list 
        l[e].push_back(s);  // considering it as an undirected graph we add both possibilities
    }
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < nv; i++)
    {
        cout << i << "--->";
        list<int>::iterator it;
        for (it = l[i].begin(); it != l[i].end(); it++)
        {
            cout << *it << " "; // printing using iterator
        }
        cout << endl;
    }
    return 0;
}