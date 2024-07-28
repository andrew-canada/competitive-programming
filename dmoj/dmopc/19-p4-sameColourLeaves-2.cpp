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

int dfsr(int n1, int par)
{
    ll nr = 1;
    for (int n2 : adj[n1])
    {
        if (n2 != par)
        {
            ll r = dfsr(n2, n1);
            if (col[n2 - 1] == 'R')
            {
                nr = (r * nr + r) % 1000000007;
            }
        }
    }
    return nr;
}

int dfsb(int n1, int par)
{
    ll nb = 1;
    for (int n2 : adj[n1])
    {
        if (n2 != par)
        {
            ll b = dfsb(n2, n1);
            if (col[n2 - 1] == 'B')
            {
                nb = (b * nb + b) % 1000000007;
            }
        }
    }
    return nb;
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
    int r = dfsr(1, -1);
    int b = dfsb(1, -1);
    printf("%d", (r + b) % 1000000007);
}