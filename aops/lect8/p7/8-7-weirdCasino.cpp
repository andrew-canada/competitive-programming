#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pows[12];
double prob[13] = {0, 0, 1.0 / 36, 2.0 / 36, 3.0 / 36, 4.0 / 36, 5.0 / 36, 6.0 / 36, 5.0 / 36, 4.0 / 36, 3.0 / 36, 2.0 / 36, 1.0 / 36};
double dist[9] = {2, 3, 4, 5, 6, 5, 4, 3, 2};
int floorDist[9], ceilDist[9];

double calc(ll chips, int rounds)
{
    map<ll, double> dp;
    dp[chips] = 1;
    for (int i = 0; i < rounds; i++)
    {
        map<ll, double> dp2;
        for (const auto &state : dp)
        {
            for (int r = 3; r <= 11; r++)
            {
                if (state.first / pows[r] % 10 >= 1)
                {
                    ll next = state.first - pows[r];
                    dp2[next] += state.second * prob[r];
                }
            }
        }
        swap(dp, dp2);
    }
    return dp[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;

    for (int i = 0; i < 9; i++)
    {
        dist[i] *= (c / 36.0);
        floorDist[i] = floor(dist[i]), ceilDist[i] = ceil(dist[i]);
    }
    pows[11] = 1;
    for (int i = 10; i >= 3; i--)
    {
        pows[i] = pows[i + 1] * 10;
    }

    double ans = 0;
    for (int i = 0; i < 512; i++)
    {
        bool valid = true;
        int sum = 0;
        ll chips = 0;
        int j = i;
        for (int k = 0; k < 9; k++)
        {
            if (j & 1)
            {
                chips += ceilDist[k], sum += ceilDist[k];
            }
            else
            {
                chips += floorDist[k], sum += floorDist[k];
            }
            if (sum > c)
            {
                valid = false;
                break;
            }
            j >>= 1;
            chips *= 10;
        }
        if (!valid || sum != c)
        {
            continue;
        }
        chips /= 10;
        double cur = calc(chips, c);
        if (cur > ans)
        {
            ans = cur;
        }
    }
    cout << fixed << setprecision(9) << ans;
}