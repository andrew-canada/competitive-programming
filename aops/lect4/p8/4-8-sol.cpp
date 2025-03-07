#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_H 100
// counts number of ways to be in this state
ll dp[MAX_H + 3][6][8]; // "the next unbuilt row is... given that the last state was... and the type is..."

/*
 most recently used:

 0 = nothing (bottom)

 1 = 2...

 2 = 3...
     3...

 3 = 122...
     122...

 4 = 112222...
     222112...

 5 = 2221...
     2121...
     2122...

We also need to subdivide patterns according to whether they do or do not
 have each of patterns 3, 4, 5 (called 2-3, 2-4, 2-6 in the analysis. We will call
these types:

         division factor to correct
 0:      1
 1:   5  4
 2:  4   6
 3:  45  12
 4: 3    3
 5: 3 5  12
 6: 34   6
 7: 345  12
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, v, t;
    cin >> h >> v >> t;
    // The extra padding is to avoid having to boundary-check at the top of
    // the tower.
    for (int row = 0; row < h + 3; ++row)
    {
        for (int prev = 0; prev <= 5; ++prev)
        {
            for (int typ = 0; typ <= 7; ++typ)
            {
                dp[row][prev][typ] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    vector<int> tvec3 = {4, 5, 6, 7, 4, 5, 6, 7};
    vector<int> tvec4 = {2, 3, 2, 3, 6, 7, 6, 7};
    vector<int> tvec5 = {1, 1, 3, 3, 5, 5, 7, 7};
    for (int row = 0; row < h; ++row)
    {
        for (int typ = 0; typ <= 7; ++typ)
        {
            // can't build 0 (i.e., can't choose to do nothing)
            // build 1. type doesn't change.
            dp[row + 1][1][typ] += dp[row][0][typ] + dp[row][2][typ];
            // build 2. type doesn't change
            dp[row + 2][2][typ] += dp[row][0][typ] + dp[row][1][typ] + dp[row][3][typ] + dp[row][4][typ] + dp[row][5][typ];
            // build 3. type may change
            if (v % 3 == 0)
            {
                dp[row + 2][3][tvec3[typ]] += 3 * (dp[row][0][typ] + dp[row][2][typ]);
            }
            // build 4
            if (v % 6 == 0)
            {
                dp[row + 2][4][tvec4[typ]] += 6 * (dp[row][0][typ] + dp[row][2][typ]);
            }
            // build 5
            if (v % 4 == 0)
            {
                dp[row + 3][5][tvec5[typ]] += 4 * (dp[row][0][typ] + dp[row][2][typ]);
            }
        }
    }
    ll total = 0;
    vector<ll> divvec;
    // For T = 0, all of the stuff we did regarding separating into types is
    // completely meaningless.
    if (t == 0)
    {
        divvec = {1, 1, 1, 1, 1, 1, 1, 1};
    }
    else
    {
        divvec = {1, 4, 6, 12, 3, 12, 6, 12};
    }
    for (int prev = 1; prev <= 5; ++prev)
    {
        for (int typ = 0; typ <= 7; ++typ)
        {
            total += (dp[h][prev][typ] / divvec[typ]);
        }
    }
    cout << total << '\n';
}