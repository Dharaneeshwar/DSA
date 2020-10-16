#include <iostream>
#include <vector>
using namespace std;
int nv, cost[10][10];
bool isValid(int i, int j, vector<bool> inMST)
{
    if (i == j)
        return false;
    if (inMST[i] == false && inMST[j] == false)
        return false;
    else if (inMST[i] == true && inMST[j] == true)
        return false;
    return true;
}

void primMST()
{
    vector<bool> inMST(nv, false);
    inMST[0] = true;

    int ne = 0, min_cost = 0;
    while (ne < nv - 1)
    {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv; j++)
            {
                if (cost[i][j] < min)
                {
                    if (isValid(i, j, inMST))
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1)
        {
            //cout<<"Edge: "<<a<<"->"<<b<<" = "<<min<<endl;
            ne++;
            min_cost += min;
            inMST[b] = inMST[a] = true;
        }
    }
    cout << "\nMinimun cost=" << min_cost;
}
int main()
{
    cin >> nv;
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    primMST();
    return 0;
}