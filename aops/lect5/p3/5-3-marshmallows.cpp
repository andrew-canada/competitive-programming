#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5 + 5;
vector<int> adjL[mxN];
int ans = 0;

void dfs(int node, int parent)
{
    bool isLeaf = true;
    for (int neighbor : adjL[node])
    {
        if (neighbor != parent)
        {
            isLeaf = false;
            dfs(neighbor, node);
        }
    }
    if (isLeaf)
    {
        ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        adjL[x].push_back(i);
        adjL[i].push_back(x);
    }

    dfs(1, -1);

    cout << (ans + 1) / 2 << '\n';
}