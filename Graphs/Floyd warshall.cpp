#include <iostream>
using namespace std;
int n, adj_mat[10][10];
void floyd()
{
    int P[n][n], i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            P[i][j] = adj_mat[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                P[i][j] = (P[i][j] || (P[i][k] && P[k][j]));
            }
        }
        cout << "P" << k << " is:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "  " << P[i][j];
            }
            cout << endl;
        }
    }
    cout << "P" << k - 1 << " is the path matrix of the given graph";
}
int main()
{
    int orgin, dest;
    cin >> n;
    if (n <= 1)
        cout << "Graph doesn't exist";
    else
    {
        int me = n * (n - 1);
        while (1)
        {
            cin >> orgin >> dest;
            if (orgin == -1 && dest == -1)
                break;
            else if (orgin < 0 || orgin >= n || dest < 0 || dest >= n)
                cout << "Invalid Edge Input:" << endl;
            else
                adj_mat[orgin][dest] = 1;
        }
        cout << "\nadjacency_matrixacency Matrix" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "  " << adj_mat[i][j];
            }
            cout << endl;
        }
        floyd();
    }
}