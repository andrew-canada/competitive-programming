#include <bits/stdc++.h>
using namespace std;

long long numberOfSubsequences(vector<int> &nums)
{
    int n = nums.size();
    map<int, vector<array<int, 2>>> mp;
    long long ans = 0;
    for (int i = 0; i < n - 4; i++)
    {
        for (int j = i + 4; j < n; j++)
        {
            mp[nums[i] * nums[j]].push_back({i, j});
        }
    }
    for (int p = 0; p < n - 4; p++)
    {
        for (int r = p + 4; r < n; r++)
        {
            int prod = nums[p] * nums[r];
            if (mp.find(prod) != mp.end())
            {
                for (const auto &val : mp[prod])
                {
                    int q = val[0], s = val[1];
                    if (q - p > 1 && r - q > 1 && s - r > 1)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums1 = {1, 2, 3, 4, 3, 6, 1};
    vector<int> nums2 = {3, 4, 3, 4, 3, 4, 3, 4};

    cout << numberOfSubsequences(nums1) << endl; // Output: 1
    cout << numberOfSubsequences(nums2) << endl; // Output: 3

    return 0;
}