#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    string s;
    cin >> s;
    int ans = 9, team1 = 0, team2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
        {
            team2 += s[i] == '1';
        }
        else
        {
            team1 += s[i] != '0';
        }
        if (team1 > team2 + (10 - i) / 2)
        {
            ans = min(ans, i);
        }
        if (team2 > team1 + (9 - i) / 2)
        {
            ans = min(ans, i);
        }
    }
    team1 = 0, team2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
        {
            team2 += s[i] != '0';
        }
        else
        {
            team1 += s[i] == '1';
        }
        if (team1 > team2 + (10 - i) / 2)
        {
            ans = min(ans, i);
        }
        if (team2 > team1 + (9 - i) / 2)
        {
            ans = min(ans, i);
        }
    }
    cout << ans + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}