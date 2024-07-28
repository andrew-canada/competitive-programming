#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 500, M = 1e9 + 7;

ll dp[mxN * (mxN + 1) / 2 + 1];

int main()
{
    int n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << "0\n";
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = i * (i + 1) / 2; s >= i; s--)
        {
            dp[s] = (dp[s] + dp[s - i]) % M;
        }
    }
    cout << dp[sum / 2] * ((M + 1) / 2) % M << "\n";
}