#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    set<char> chars;
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        chars.insert(c);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && chars.count(s[j]))
        {
            j++;
        }
        ll num = j - i;
        ans += num * (num + 1) / 2;
        i = j;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
}