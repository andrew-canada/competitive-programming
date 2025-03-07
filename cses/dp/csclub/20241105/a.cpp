#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int numberOfSubordinates[mxN + 1];
vector<int> subordinates[mxN + 1];

void dfs(int n)
{
    numberOfSubordinates[n] = 1;
    for (int i : subordinates[n])
    {
        dfs(i);
        numberOfSubordinates[n] += numberOfSubordinates[i];
    }
}

int main()
{
    int n, boss;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> boss;
        subordinates[boss].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << numberOfSubordinates[i] - 1 << " ";
    }
}