#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    long long ans = 0;
    map<char, vector<int>> nxt;
    for (int i = 0; i < s.size(); i++)
    {
        nxt[s[i]].push_back(i);
    }
    vector<bool> vis(s.size(), 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (vis[i])
        {
            continue;
        }
        if (nxt.find('z' - (s[i] - 'a')) != nxt.end())
        {
            auto &positions = nxt['z' - (s[i] - 'a')];
            auto it = lower_bound(positions.begin(), positions.end(), i);
            if (it != positions.begin())
            {
                --it;
                int j = *it;
                if (!vis[j])
                {
                    ans += i - j;
                    vis[i] = true;
                    vis[j] = true;
                    positions.erase(it);
                }
            }
        }
    }
    cout << ans << '\n';
}