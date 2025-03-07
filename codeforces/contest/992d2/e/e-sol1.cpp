
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int N;
vector<int> G[2000];
int pr[2000];
void dfs(int u, int p)
{
    pr[u] = p;
    for (int v : G[u])
        if (v != p)
            dfs(v, u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T--;)
    {
        int Q;
        cin >> N >> Q;
        for (int i = 0; i < N; i++)
            G[i].clear();
        for (int i = 1; i < N; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0, -1);
        for (; Q--;)
        {
            int v, p;
            cin >> v >> p;
            v--;
            vector<int> V;
            while (v != 0)
            {
                V.push_back(v);
                v = pr[v];
            }
            int ans = V.size();
            vector<int> d;
            for (int i = 1; i < V.size(); i += 2)
                d.push_back(G[V[i]].size());
            sort(d.begin(), d.end());
            for (int i = 0; i < (int)d.size() - p; i++)
                ans += 2 * d[i] - 2;
            cout << ans << "\n";
        }
    }
}