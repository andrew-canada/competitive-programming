#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int a[mxN + 1];
bool dp[mxN + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + a[i]; j <= n; j += a[i])
        {
            if (a[j] > a[i] && !dp[j])
            {
                dp[i] = true;
                break;
            }
        }
        for (int j = i - a[i]; j >= 1; j -= a[i])
        {
            if (a[j] > a[i] && !dp[j])
            {
                dp[i] = true;
                break;
            }
        }
    }

    string ans;
    for (int i = 1; i <= n; i++)
    {
        ans += (dp[i] ? 'A' : 'B');
    }
    cout << ans << '\n';
}