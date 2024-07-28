#include <bits/stdc++.h>

using namespace std;

const int mxN = 405;

int ball[mxN];
int dp[mxN][mxN];
int psa[mxN];

int main()
{
    int n;
    scanf("%d", &n);
    int maxB = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ball[i]);
        psa[i] = psa[i - 1] + ball[i];
        dp[i][i] = ball[i];
        if (ball[i] > maxB)
        {
            maxB = ball[i];
        }
    }
    for (int range = 1; range < n; range++)
    {
        for (int l = 0; l < n - range; l++)
        {
            int r = l + range;
            int l1 = l, r1 = r;
            while (l1 < r1)
            {
                if (dp[l][l1] && dp[l][l1] == dp[r1][r] && (r1 == l1 + 1 || dp[l1 + 1][r1 - 1]))
                {
                    dp[l][r] = max(dp[l][r], dp[l][l1] + dp[l1 + 1][r1 - 1] + dp[r1][r]);
                    maxB = max(maxB, dp[l][r]);
                    break;
                }
                if (psa[l1] - psa[l - 1] > psa[r] - psa[r1 - 1])
                {
                    r1--;
                }
                else
                {
                    l1++;
                }
            }
        }
    }
    printf("%d\n", maxB);
}