#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1000 + 19;

vector<int> A[N];
int f[2][N], fa[N], w[N], v[N], W[N], V[N];
int n, m, maxW, c;

void Upd(int &x, int y)
{
    x = max(x, y);
}
int getf(int x)
{
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}
void Union(int x, int y)
{
    x = getf(x), y = getf(y);
    if (x != y)
    {
        fa[x] = y;
        W[y] += W[x];
        V[y] += V[x];
        for (int i = 0; i < A[x].size(); i++)
        {
            A[y].pb(A[x][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> n >> m >> maxW;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        W[i] = w[i];
        V[i] = v[i];
        A[i].pb(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
        {
            c ^= 1;
            for (int j = 0; j <= maxW; j++)
            {
                f[c][j] = f[c ^ 1][j];
            }
            for (int j = W[i]; j <= maxW; j++)
            {
                Upd(f[c][j], f[c ^ 1][j - W[i]] + V[i]);
            }
            for (int x : A[i])
            {
                for (int j = w[x]; j <= maxW; j++)
                {
                    Upd(f[c][j], f[c ^ 1][j - w[x]] + v[x]);
                }
            }
        }
    }
    cout << f[c][maxW] << '\n';
}