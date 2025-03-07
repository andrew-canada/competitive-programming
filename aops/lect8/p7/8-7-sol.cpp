#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Make this table to avoid recomputing powers of ten.
ll powers_of_ten[20];

double score_distribution(ll dist, int rounds)
{
    vector<double> probs = {0, 0, 1.0 / 36, 2.0 / 36, 3.0 / 36, 4.0 / 36, 5.0 / 36, 6.0 / 36,
                            5.0 / 36, 4.0 / 36, 3.0 / 36, 2.0 / 36, 1.0 / 36};
    map<ll, double> dp;
    dp[dist] = 1.0;
    for (int r = 0; r < rounds; ++r)
    {
        map<ll, double> new_dp;
        for (auto &p : dp)
        {
            // Assume we never put chips on 2 or 12.
            for (int roll = 3; roll <= 11; ++roll)
            {
                if ((p.first / powers_of_ten[roll]) % 10 >= 1)
                {
                    ll nxt = p.first - powers_of_ten[roll];
                    new_dp[nxt] += p.second * probs[roll];
                }
            }
        }
        swap(dp, new_dp);
    }
    return dp[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    powers_of_ten[11] = 1; // the ones digit will correspond to a roll of 11
    for (int i = 10; i >= 3; --i)
    {
        powers_of_ten[i] = powers_of_ten[i + 1] * 10;
    }
    vector<double> raw_dist = {2, 3, 4, 5, 6, 5, 4, 3, 2};
    int c;
    cin >> c;
    int base_dist_floor[9];
    int base_dist_ceil[9];
    for (int i = 0; i < 9; ++i)
    {
        raw_dist[i] *= (c / 36.0);
        base_dist_floor[i] = floor(raw_dist[i]);
        base_dist_ceil[i] = ceil(raw_dist[i]);
    }
    // for each index, try either the floor or the ceil
    int poss = 1;
    for (int i = 0; i < 9; ++i)
    {
        poss *= 2;
    }
    double best = 0;
    for (int i = 0; i < poss; ++i)
    {
        int j = i;
        bool ok = true;
        ll cand_dist = 0;
        int sum = 0;
        for (int k = 0; k < 9; ++k)
        {
            if (j % 2 == 0)
            {
                cand_dist += base_dist_floor[k];
                sum += base_dist_floor[k];
            }
            else
            {
                cand_dist += base_dist_ceil[k];
                sum += base_dist_ceil[k];
            }
            // Abort bad allocations early, saving some time.
            if (sum > c)
            {
                ok = false;
                break;
            }
            j /= 2;
            cand_dist *= 10;
        }
        if (!ok || (sum != c))
        {
            continue;
        }
        // get rid of the extra factor of 10 added at the end of the last loop
        cand_dist /= 10;
        // check this distribution
        double res = score_distribution(cand_dist, c);
        if (res > best)
        {
            best = res;
        }
    }
    cout << fixed << setprecision(9) << best << '\n';
}