#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

#define LOCAL
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back

int n;
vector<int> adj[300005];
char col[300005];
bool vis[300005];
int v1, v2;
int numNodes;
int numTrees;

int dfs(int n1)
{
    ll num = 1;
    vis[n1] = true;
    for (int n2 : adj[n1])
    {
        if (!vis[n2] && col[n2 - 1] == col[n1 - 1])
        {
            ll nodes = dfs(n2);
            num = nodes + 1;
        }
    }
    return num;
}

int main()
{
#ifdef LOCAL
    freopen("19p4.in", "r", stdin);
#endif
    scanf("%d", &n);
    scanf("%s", &col);
    REP(i, 0, n - 1)
    {
        scanf("%d %d", &v1, &v2);
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            numNodes = dfs(i) % 1000000007;
            numTrees += numNodes * (numNodes + 1) / 2 % 1000000007;
        }
    }
    printf("%d", numTrees);
}