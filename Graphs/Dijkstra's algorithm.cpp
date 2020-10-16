#include <iostream>
using namespace std;
int n, G[10][10], sn;
void dijkstra()
{
    int distance[n], visited[n], parent[n], cost[n][n];
    int i, j, minDis, nextNode;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = 999;
            else
                cost[i][j] = G[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[sn][i];
        visited[i] = 0;
        parent[i] = sn;
    }
    distance[sn] = 0;
    visited[sn] = 1;
    int count = 1;
    while (count < n - 1)
    {
        minDis = 999;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < minDis && !visited[i])
            {
                minDis = distance[i];
                nextNode = i;
            }
        }
        visited[nextNode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (minDis + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDis + cost[nextNode][i];
                    parent[i] = nextNode;
                }
            }
        }
        count++;
    }
    for (i = 0; i < n; i++)
    {
        if (i != sn)
        {
            cout << "\nDistance of node" << i << "=" << distance[i];
            cout << "\nPath=" << i;
            j = i;
            do
            {
                j = parent[j];
                cout << "<-" << j;
            } while (j != sn);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    cin >> sn;
    dijkstra();
    return 0;
}