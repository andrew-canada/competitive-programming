#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 200000;
ll lis[MAX_N];

ll solve(int left_idx, int right_idx)
{ // inclusive endpoints
    if (left_idx == right_idx)
    { // base case
        return lis[left_idx];
    }
    ll answer = 0;
    int mid_idx = (left_idx + right_idx) / 2;
    // D&C: either the interval is totally within the left half...
    answer = max(answer, solve(left_idx, mid_idx));
    // ...or totally within the right half...
    answer = max(answer, solve(mid_idx + 1, right_idx));
    // ...or spans the two. In this case we should go as far left as possible in
    // the left half (starting from the right end), and as far right as possible
    // in the right half (starting from the left end).
    ll left_best = 0;
    ll cumulative = 0;
    for (int i = mid_idx; i >= left_idx; i--)
    {
        cumulative += lis[i];
        left_best = max(left_best, cumulative);
    }
    ll right_best = 0;
    cumulative = 0;
    for (int i = mid_idx + 1; i <= right_idx; i++)
    {
        cumulative += lis[i];
        right_best = max(right_best, cumulative);
    }
    return max(answer, left_best + right_best);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> lis[i];
    }
    cout << solve(0, n - 1) << '\n';
}