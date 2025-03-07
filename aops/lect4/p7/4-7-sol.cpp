#include <bits/stdc++.h>
using namespace std;

// For each "row" of the DP, declare at the outset what our target smallest line
// length will be. Don't even bother keeping track of whether we've actually
// attained it.
#define MAX_N 5000
#define MAX_B 5000
int dp[(MAX_N + 1)][(MAX_B + 1)];

#define INVALID INT_MAX

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int word_lengths[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> word_lengths[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = a; j <= b; ++j)
        {
            dp[i][j] = INVALID;
        }
    }
    for (int j = a; j <= b; ++j)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        // Let's see how far we can go from this word...
        int k = i;
        int cumulative = 0;
        while ((k < n) && (cumulative + word_lengths[k] <= b))
        {
            cumulative += word_lengths[k];
            // We can only consider a line break if
            // 1. cumulative is at least j, or else it violates our claim that j
            //    is the smallest line we ever make
            // 2. cumulative is at least a, or else it violates the rules on line
            //    length.
            for (int j = a; j <= b; ++j)
            {
                if (cumulative >= j)
                {
                    dp[k + 1][j] = min(dp[k + 1][j], max(dp[i][j], cumulative - j));
                }
            }
            k++;
        }
    }
    int best = INVALID;
    for (int j = a; j <= b; ++j)
    {
        best = min(best, dp[n][j]);
    }
    cout << best << '\n';
}
