#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 15, mxM = 2e5, M = 1e9 + 7;

int n, eu[1 << mxN], ev[1 << mxN];
vector<int> adjL[1 << mxN], ans;
bool vis[1 << mxN];

/*
traverse graph
1. start at node 0
2. dfs to opposite node of edges adjacent to current
3. backtrack to find order of edges
*/
void dfs(int u = 0)
{
    while (adjL[u].size())
    {
        int e = adjL[u].back();
        adjL[u].pop_back();
        if (vis[e])
        {
            continue;
        }
        vis[e] = true;
        dfs(u ^ eu[e] ^ ev[e]);
        ans.pb(e);
    }
}

int main()
{
    int n;
    cin >> n;
    /*
        build graph
        1. create starting node for each edge
        2. create ending node for each edge
        3. build adjacency list (edges connected to starting node)
    */
    for (int i = 0; i < (1 << n); i++)
    {
        eu[i] = i / 2;
        ev[i] = i & ((1 << (n - 1)) - 1);
        adjL[eu[i]].pb(i);
    }
    dfs();
    /*
    print path
    1. mod edge numbers (appending 0 vs appending 1 to path)
    2. print trailing zeros to complete cycle (1000... n-1 zeros)
    */
    for (int i : ans)
    {
        cout << i % 2;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << 0;
    }
}