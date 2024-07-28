#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 100, mxX = 1e6;

int c[mxN + 1], dp[mxX + 1];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i >= c[j])
            {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
}