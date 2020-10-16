#include <bits/stdc++.h>
using namespace std;
int V, parent[10], cost[10][10];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void kruskalMST()
{
    int mincost = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1)
    {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        edge_count++;
        mincost += min;
    }
    cout << "Minimum cost = " << mincost;
}
int main()
{
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    kruskalMST();
    return 0;
}
