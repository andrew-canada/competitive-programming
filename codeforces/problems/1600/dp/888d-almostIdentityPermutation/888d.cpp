#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, int> mp = {{2, 1}, {3, 2}, {4, 9}};

ll ncr(int n, int r)
{
    ll ans = 1;
    for (int i = n; i > n - r; i--)
    {
        ans *= i;
    }
    for (int i = 2; i <= r; i++)
    {
        ans /= i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    ll ans = 1;
    for (int i = 2; i <= k; i++)
    {
        ans += ncr(n, i) * mp[i];
    }
    cout << ans;
}