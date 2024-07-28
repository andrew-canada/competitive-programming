#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back

int n;
vector<int> adj[300005];
char col[300005];
int v1, v2;

pair<int, int> dfs(int n1, int par)
{
    ll nr = 1, nb = 1;
    for (int n2 : adj[n1])
    {
        if (n2 != par)
        {
            auto [r, b] = dfs(n2, n1);
            nr = nr * r % 1000000007;
            nb = nb * b % 1000000007;
        }
    }
    return {nr, nb};
}

int main()
{
    scanf("%d", &n);
    scanf("%s", &col);
    REP(i, 0, n - 1)
    {
        scanf("%d %d", &v1, &v2);
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    auto [r, b] = dfs(1, -1);
    printf("%d", (r + b) % 1000000007);
}