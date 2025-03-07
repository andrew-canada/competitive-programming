#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e4;

int neg, pos, cur, cycDiff, numNode, dfsRoot;
vector<array<int, 2>> adjL1[mxN + 1], adjL2[mxN + 1];
bool vis[mxN + 1], cycFound;
stack<int> stk;

void dfs(int u)
{
    vis[u] = true;
    for (auto &[v, d] : adjL1[u])
    {
        if (!vis[v])
        {
            cur += d;
            neg = min(neg, cur), pos = max(pos, cur);
            dfs(v);
        }
    }
}

void dfs1(int u)
{
    vis[u] = true;
    for (auto &[v, d] : adjL1[u])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    stk.push(u);
}

void dfs2(int u)
{
    vis[u] = true;
    for (auto &[v, d] : adjL2[u])
    {
        if (!vis[v])
        {
            cycDiff += d;
            numNode++;
            dfs2(v);
        }
        if (numNode > 0 && v == dfsRoot)
        {
            cycDiff += d;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("2-3.in", "r", stdin);
    int t, s, n, x, a, b, d;
    cin >> t;
    while (t--)
    {
        cin >> s >> n >> x;
        while (s--)
        {
            cin >> a >> b >> d;
            --a, --b;
            adjL1[a].pb({b, d});
            adjL2[b].pb({a, d});
        }
        // cout << adjL1[1].size() << " | " << adjL2[1].size() << '\n';
        neg = 0, pos = 0, cur = 0;
        dfs(0);
        if (1e6 - pos <= x && x <= 1e6 - neg)
        {
            cout << "YES\n";
        }
        else
        {
            memset(vis, false, sizeof(vis));
            cycFound = false;
            for (int u = 0; u < n; u++)
            {
                if (!vis[u])
                {
                    dfs1(u);
                }
            }
            memset(vis, false, sizeof(vis));
            while (!stk.empty())
            {
                if (!vis[stk.top()])
                {
                    cycDiff = 0, numNode = 0, dfsRoot = stk.top();
                    dfs2(stk.top());
                    // cout << stk.top() << " " << cycDiff << '\n';
                    if ((cycDiff > 0 && x <= 1e6) || (cycDiff < 0 && x >= 1e6))
                    {
                        cout << "YES\n";
                        cycFound = true;
                        break;
                    }
                }
                stk.pop();
            }
            if (!cycFound)
            {
                cout << "NO\n";
            }
        }
        for (int i = 0; i < n; i++)
        {
            adjL1[i].clear();
            adjL2[i].clear();
        }
        memset(vis, false, sizeof(vis));
    }
}