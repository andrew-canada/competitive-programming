#include <bits/stdc++.h>
using namespace std;

long long numberOfSubsequences(vector<int> &nums)
{
    int n = nums.size();
    map<int, vector<array<int, 2>>> mp;
    set<int> prods;
    long long ans = 0;
    for (int i = 0; i < n - 4; i++)
    {
        for (int j = i + 4; j < n; j++)
        {
            mp[nums[i] * nums[j]].push_back({i, j});
            // cout << nums[i] * nums[j] << ": " << i << " " << j << '\n';
            prods.insert(nums[i] * nums[j]);
        }
    }
    for (const int &prod : prods)
    {
        if (mp[prod].size() > 1)
        {
            for (int i = 0; i < mp[prod].size() - 1; i++)
            {
                for (int j = i + 1; j < mp[prod].size(); j++)
                {
                    int p = mp[prod][i][0], r = mp[prod][i][1];
                    int q = mp[prod][j][0], s = mp[prod][j][1];
                    // cout << prod << ": " << p << " " << r << " | " << q << " " << s << '\n';
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