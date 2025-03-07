#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> res(n);
        int lst = 1;
        res[0] = lst;

        function<void(int, int)> dfs = [&](int v, int p)
        {
            for (int to : g[v])
            {
                if (to == p)
                    continue;
                res[to] = lst + 1;
                while (res[to] != res[v] + 1 &&
                       (res[to] % 2 != res[v] % 2 || res[to] - res[v] == 2))
                {
                    res[to]++;
                }
                lst = res[to];
                dfs(to, v);
            }
        };

        dfs(0, 0);
        for (int i : res)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}