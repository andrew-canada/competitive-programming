#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int numSub[mxN + 1];

int dfs(int n)
{
    if (!adjL[n].size())
    {
        return 1;
    }
    for (int i : adjL[n])
    {
        numSub[n] += dfs(i);
    }
    return numSub[n] + 1;
}

int main()
{
    int n;
    cin >> n;
    int boss;
    for (int i = 2; i <= n; i++)
    {
        cin >> boss;
        adjL[boss].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << numSub[i] << " ";
    }
}