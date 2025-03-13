#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    string s;
    cin >> s;
    int ans = INF;
    vector<pair<char, int>> freq;
    for (char c : s)
    {
        if (freq.empty() || freq.back().first != c)
        {
            freq.push_back({c, 1});
        }
        else
        {
            freq.back().second++;
        }
    }
    for (int i = 1; i < freq.size() - 1; i++)
    {
        if (freq[i - 1].first != freq[i + 1].first)
        {
            ans = min(ans, freq[i].second + 2);
        }
    }
    cout << (ans > s.size() ? 0 : ans) << '\n';
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