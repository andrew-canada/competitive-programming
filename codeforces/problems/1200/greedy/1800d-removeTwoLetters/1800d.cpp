#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = n - 1;
    for (int i = 1; i + 1 < n; i++)
    {
        if (s[i - 1] == s[i + 1])
        {
            ans--;
        }
    }
    cout << ans << '\n';
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