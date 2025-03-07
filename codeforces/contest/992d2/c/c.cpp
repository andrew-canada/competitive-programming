#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int sum(vector<int> &s)
{
    int ans = 0;
    for (int l = 0; l < s.size(); l++)
    {
        for (int r = l; r < s.size(); r++)
        {
            int cur = INF;
            for (int i = l; i <= r; i++)
            {
                cur = min(cur, s[i]);
            }
            ans += cur;
        }
    }
    return ans;
}

int maxSum(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i * (n - i + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int cur = 0;
        int target = maxSum(n);
        bool found = false;
        vector<int> s(n);
        iota(s.begin(), s.end(), 1);
        do
        {
            int val = sum(s);
            if (val == target)
            {
                cur += 1;
                if (cur == k)
                {
                    found = true;
                    for (int i : s)
                    {
                        cout << i << " ";
                    }
                    cout << '\n';
                    break;
                }
            }
        } while (next_permutation(s.begin(), s.end()));
        if (!found)
        {
            cout << "-1\n";
        }
    }
}