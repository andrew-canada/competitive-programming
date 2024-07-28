#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e6, mxX = 1e6, M = 1e9 + 7;

int dp[mxN + 1];

int main()
{
    int n, ans = 0;
    cin >> n;
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int i1 = i;
        while (i1)
        {
            dp[i] = min(dp[i], dp[i - i1 % 10] + 1);
            i1 /= 10;
        }
    }
    cout << dp[n];
}