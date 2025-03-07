#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;

int arr[mxN + 1], psa[mxN + 1];

int main()
{
    int n, ans = 0;
    cin >> n;
    psa[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        psa[i] = psa[i - 1] + arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans = max({ans, psa[i]});
    }
    cout << ans;

    // ndp[i]=max(dp[i]+curTerm, dp[i-1]-curTerm);
}

/*
-3
6
-2
*/