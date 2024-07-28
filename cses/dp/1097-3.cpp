#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3;

int arr[mxN + 1];
array<ll, 2> dp[mxN + 1][mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = {arr[i], 0};
                continue;
            }
            if (dp[i + 1][j][1] + arr[i] > dp[i][j - 1][1] + arr[j])
            {
                dp[i][j] = {dp[i + 1][j][1] + arr[i], dp[i + 1][j][0]};
            }
            else
            {
                dp[i][j] = {dp[i][j - 1][1] + arr[j], dp[i][j - 1][0]};
            }
        }
    }
    cout << dp[0][n - 1][0];
}