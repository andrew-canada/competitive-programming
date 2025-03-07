#include <bits/stdc++.h>
using namespace std;

int countInterestingPairs(vector<int> &a, long long x, long long y)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        long long low = x - a[i];
        long long high = y - a[i];

        auto lower = lower_bound(a.begin() + i + 1, a.end(), low);
        auto upper = upper_bound(a.begin() + i + 1, a.end(), high);

        count += distance(lower, upper);
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        cout << countInterestingPairs(a, x, y) << '\n';
    }

    return 0;
}