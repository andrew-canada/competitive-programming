#include <bits/stdc++.h>
using namespace std;

#define INVALID 100000000

#define MAX_L 1000
int dp[MAX_L + 1][MAX_L + 1];

// Top-down DP + memoization is probably OK for this problem since the
// call stack shouldn't get bigger than 2 * MAX_L.

int solve(int i1, int i2, int l1, int l2, int c, int d, int i, string &s1, string &s2)
{ // pass strings by reference, NOT by value
    if (i1 == l1)
    {                         // reached end of string 1
        return i * (l2 - i2); // insert the rest of string 2
    }
    else if (i2 == l2)
    {                         // reached end of string 2
        return d * (l1 - i1); // delete the rest of string 1
    }
    if (dp[i1][i2] != INVALID)
    {
        return dp[i1][i2];
    }
    int best_answer = INVALID;
    if (s1[i1] == s2[i2])
    { // advance both (i.e. do nothing)
        best_answer = min(best_answer, solve(i1 + 1, i2 + 1, l1, l2, c, d, i, s1, s2));
    }
    else
    {
        // try editing s1 to match s2 and moving ahead
        best_answer = min(best_answer, c + solve(i1 + 1, i2 + 1, l1, l2, c, d, i, s1, s2));
    }
    // delete the offending character of s1
    best_answer = min(best_answer, d + solve(i1 + 1, i2, l1, l2, c, d, i, s1, s2));
    // insert a match for the next s2 letter right before the current s1 letter
    best_answer = min(best_answer, i + solve(i1, i2 + 1, l1, l2, c, d, i, s1, s2));
    dp[i1][i2] = best_answer;
    return best_answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l1, l2, c, d, i;
    cin >> l1 >> l2 >> c >> d >> i;
    for (int i1 = 0; i1 <= l1; ++i1)
    {
        for (int i2 = 0; i2 <= l2; ++i2)
        {
            dp[i1][i2] = INVALID;
        }
    }
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(0, 0, l1, l2, c, d, i, s1, s2) << '\n';
}