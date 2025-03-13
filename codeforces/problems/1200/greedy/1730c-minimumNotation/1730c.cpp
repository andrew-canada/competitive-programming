#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

void solve()
{
    string s, ans = "", nums = "0123456789";
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1), suffMin(n + 1, 9), dig(10, 0);
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suffMin[i] = min(suffMin[i + 1], a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < suffMin[i]; j++)
        {
            while (dig[j])
            {
                dig[j]--;
                ans += nums[j];
            }
        }
        if (a[i] == suffMin[i])
        {
            ans += nums[a[i]];
        }
        else
        {
            dig[min(9, a[i] + 1)]++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (dig[i])
        {
            dig[i]--;
            ans += nums[i];
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