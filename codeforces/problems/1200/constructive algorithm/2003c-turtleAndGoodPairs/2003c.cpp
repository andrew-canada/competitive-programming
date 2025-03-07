#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, tot = 0;
    string str, ans;
    cin >> n;
    vector<int> num(26, 0);
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        num[str[i] - 'a']++;
    }
    while (ans.size() < n)
    {
        for (int i = 0; i < 26; i++)
        {
            if (!num[i])
            {
                continue;
            }
            char c = 'a' + i;
            ans += c;
            num[i]--;
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