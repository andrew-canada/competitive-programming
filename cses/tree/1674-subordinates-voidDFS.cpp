#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int s[mxN + 1];

void dfs(int n)
{
    s[n] = 1;
    for (int i : adjL[n])
    {
        dfs(i);
        s[n] += s[i];
    }
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
        cout << s[i] - 1 << " ";
    }
}