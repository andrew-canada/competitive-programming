#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6, M = 1e9 + 7;

ll dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = ((i - 1) * dp[i - 1] + (i - 1) * dp[i - 2]) % M;
    }
    cout << dp[n];
}