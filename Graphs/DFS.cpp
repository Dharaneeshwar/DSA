#include <iostream>
#include <list>
using namespace std;
int nv;
list<int> stack;
list<int>::iterator it;

void dfs(int i, int *visited, list<int> *l)
{
    if (visited[i] == 0)
        cout << i << " ";
    visited[i] = 1;
    for (it = l[i].begin(); it != l[i].end(); it++)
    {
        if (visited[*it] == 0)
        {
            stack.push_back(*it);
        }
    }
    while (!(stack.empty()))
    {
        int back = stack.back();
        stack.pop_back();
        dfs(back, visited, l);
    }
}
int main()
{

    cin >> nv; // number of vertex
    nv++;
    list<int> l[nv];
    int visited[nv];
    for (int i = 0; i < nv; i++)
    {
        visited[i] = 0;
    }
    int s, e;
    while (true)
    {
        cin >> s >> e;
        if (s == -1 && e == -1)
            break;
        l[s].push_back(e); // adding the edge to list
        l[e].push_back(s); // considering it as an undirected graph we add both possibilities
    }
    cout << "DFS : ";
    dfs(0, visited, l);

    return 0;
}