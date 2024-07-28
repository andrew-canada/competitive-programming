#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back

int n;
vector<int> adj[100005];
int v1, v2;
pair<int, int> dfs(int n1, int par)
{
    ll nb = 1, nw = 1;
    for (int n2 : adj[n1])
    {
        if (n2 != par)
        {
            auto [b, w] = dfs(n2, n1);
            nb = nb * w % 1000000007;
            nw = nw * (b + w) % 1000000007;
        }
    }
    return {nb, nw};
}

int main()
{
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d %d", &v1, &v2);
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    auto [b, w] = dfs(1, -1);
    printf("%d", (b + w) % 1000000007);
}