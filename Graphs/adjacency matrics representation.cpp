#include <iostream>
using namespace std;
int main()
{
    int nv, ne;
    cout << "Please enter the number of nodes in the graph" << endl;
    cout << "Please enter the number of edges in the graph" << endl;
    cin >> nv >> ne; // number of vertex and edge
    cout << "Is the graph directed" << endl;
    string is_directed; // directed graph or not
    cin >> is_directed;
    int arr[nv][nv];
    cout << "Adjacency Matrix Representation:" << endl;  
    // initializing the martix
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            arr[i][j] = 0;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int s, e, w;
    for (int i = 0; i < ne; i++)
    {
        cout << "Enter the start node, end node and weight of edge no " << i + 1 << endl;
        cin >> s >> e >> w;
        if (is_directed == "yes")
        {
            arr[s - 1][e - 1] = w; // assigning the weight to the edge  
        }
        else
        {
            arr[s - 1][e - 1] = w;
            arr[e - 1][s - 1] = w;
        }
    }
    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < nv; i++) // print the matrix
    {
        for (int j = 0; j < nv; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}