#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int deg[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v, tot = 0, a = 0;
    char p;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        --u, --v;
        deg[u]++, deg[v]++;
        tot += 2;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        if (p == 'A')
        {
            a += deg[i];
        }
    }
    cout << fixed << setprecision(9) << 1.0 * a / tot;
}