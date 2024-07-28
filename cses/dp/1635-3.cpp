#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 100, mxX = 1e6, M = 1e9 + 7;

ll c[mxN + 1], dp[mxX + 1];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= x; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j >= c[i])
            {
                dp[j] = (dp[j] + dp[j - c[i]]) % M;
            }
        }
    }
    cout << dp[x];
}