#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6;

int fav[mxN + 1];
double dp[mxN + 1];
map<int, int> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fav[i];
    }
    if (fav[1] == fav[n])
    {
        cout << 1;
        return 0;
    }
    // dp[i] = prob person i gets their burger
    double ans = 0;
    // last person of a burger type
    mp[fav[n]] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (fav[i] == fav[1])
        {
            dp[i] = 1;
        }
        else if (mp[fav[i]])
        {
            dp[i] = dp[mp[fav[i]]];
        }
        else
        {
            // n-i+1 burger remain
            // 1/numB take coach, rem
            dp[i] = (ans + 1) / (n - i + 1);
        }
        ans += dp[i];
        if (!mp[fav[i]])
        {
            mp[fav[i]] = i;
        }
    }
    cout << fixed << setprecision(8) << ans / n;
}