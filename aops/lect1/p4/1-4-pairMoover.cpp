#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
bool seeG;

bool ord(ll cows, ll oo)
{
    int i = n - 1;
    while (i >= 0)
    {
        if (i == oo + 1)
        {
            --i;
            cows >>= 1;
        }
        else if (cows & 1)
        {
            if (seeG)
            {
                return false;
            }
        }
        else
        {
            seeG = true;
        }
        --i;
        cows >>= 1;
    }
    return true;
}

int bfs(ll cows, ll oo)
{
    queue<array<ll, 3>> q;
    set<ll> vis;
    q.push({cows, oo, 0});
    while (!q.empty())
    {
        array<ll, 3> cur = q.front();
        q.pop();
        for (int i = 0; i < n - 1; i++)
        {
            if (i == oo)
            {
                ++i;
                continue;
            }
            else if (i == oo + 1)
            {
                i += 2;
                continue;
            }
            else
            {
                ll nxt = cur[0];
                int two = cur[0] >> (n - i - 2);
                nxt &= 00 << (n - i - 2);
                nxt &= two << (n - oo);
                if (vis.find(nxt) != vis.end())
                {
                    continue;
                }
                if (ord(nxt, n - i - 2))
                {
                    return true;
                }
                else
                {
                    q.push({nxt, n - i - 2, cur[2] + 1});
                    vis.insert(nxt);
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        ll cows = 0, oo = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'H')
            {
                cows += 1;
            }
            else if (s[i] == 'O')
            {
                oo = i;
                cows <<= 1;
                i += 1;
            }
            cows <<= 1;
        }
        cows >>= 1;

        int ans = bfs(cows, oo);
        if (ans)
        {
            cout << ans << '\n';
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}