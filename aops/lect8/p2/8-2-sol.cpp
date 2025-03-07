#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    double pis[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> pis[i];
    }
    sort(pis, pis + n);
    double best = 0.0;
    for (int from_front = 0; from_front <= k; ++from_front)
    {
        double dp[2][k / 2 + 1];
        dp[0][0] = 1.0;
        for (int i = 1; i <= k / 2; ++i)
        {
            dp[0][i] = 0.0;
        }
        int which_next = 1;
        // Go through these K people
        for (int i = 0; i < k; ++i)
        {
            double next_pi = ((i < from_front) ? pis[i] : pis[n - 1 - (i - from_front)]);
            // Clean next
            for (int h = 0; h <= k / 2; ++h)
            {
                dp[which_next][h] = 0.0;
            }
            for (int j = 0; j <= k / 2; ++j)
            {
                if (dp[1 - which_next] == 0)
                {
                    continue;
                }
                // votes yes. If we push past the tie value, we no longer care
                //   what happens to this branch of the probability space.
                if (j < k / 2)
                {
                    dp[which_next][j + 1] += next_pi * dp[1 - which_next][j];
                }
                // votes no
                dp[which_next][j] += (1.0 - next_pi) * dp[1 - which_next][j];
            }
            which_next = 1 - which_next;
        }
        best = max(best, dp[1 - which_next][k / 2]);
    }
    cout << fixed << setprecision(9) << best << '\n';
}