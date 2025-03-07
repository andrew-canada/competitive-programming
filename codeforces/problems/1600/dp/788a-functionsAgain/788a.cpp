#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e5;

int n;
ll a[mxN + 1], ans;

void solve(int s)
{
    ll sum = 0;
    for (int i = s; i <= n; i++)
    {
        if (i % 2 == s % 2)
        {
            sum = max(sum, 0ll);
        }
        sum += a[i];
        ans = max(ans, sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        a[i] = abs(a[i + 1] - a[i]);
    }
    n--;
    for (int i = 1; i <= n; i += 2)
    {
        a[i] *= -1;
    }
    solve(2);
    for (int i = 1; i <= n; i++)
    {
        a[i] *= -1;
    }
    solve(1);
    cout << ans << '\n';
}