#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    int n, ans;
    string s;
    cin >> n >> s;
    ans = n + 1;
    for (int i = 0; i < 26; i++)
    {
        int l = 0, r = n - 1, num = 0;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++, r--;
            }
            else if (s[l] == 'a' + i)
            {
                l++, num++;
            }
            else if (s[r] == 'a' + i)
            {
                r--, num++;
            }
            else
            {
                num = n + 1;
                break;
            }
        }
        ans = min(ans, num);
    }
    cout << (ans == n + 1 ? -1 : ans) << '\n';
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