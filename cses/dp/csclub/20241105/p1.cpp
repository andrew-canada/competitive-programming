#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

int s[mxN + 1];
vector<int> adjL[mxN + 1];

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, boss;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> boss;
        adjL[boss].pb(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] - 1 << ' ';
    }
}