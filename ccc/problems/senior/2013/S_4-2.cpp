#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 1e6;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];

bool bfs(int a, int b)
{
    queue<int> q;
    q.push(a);
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == b)
        {
            return true;
        }
        for (int i : adjL[cur])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b);
    }
    cin >> a >> b;
    if (bfs(a, b))
    {
        cout << "yes";
    }
    else if (bfs(b, a))
    {
        cout << "no";
    }
    else
    {
        cout << "unknown";
    }
}