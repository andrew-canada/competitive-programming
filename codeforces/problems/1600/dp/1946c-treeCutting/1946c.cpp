#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
int n, k;

int dfs(int v, int p, int x, int &removed)
{
    int sz = 1;
    for (int u : adjL[v])
    {
        if (u != p)
        {
            sz += dfs(u, v, x, removed);
        }
    }
    if (sz >= x)
    {
        removed++;
        return 0;
    }
    return sz;
}

bool canAchieve(int x)
{
    int removed = 0;
    int rootSize = dfs(1, -1, x, removed);
    return (removed > k || (removed == k && rootSize >= x));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            adjL[i].clear();
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        int low = 1, high = n, ans = 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canAchieve(mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << '\n';
    }
}