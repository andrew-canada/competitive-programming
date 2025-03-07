#include <bits/stdc++.h>
using namespace std;
int maxDistinctElements(vector<int> &nums, int k)
{
    vector<pair<int, int>> ranges(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        ranges[i] = make_pair(nums[i] - k, nums[i] + k);
    }
    vector<pair<int, bool>> points;
    for (auto &range : ranges)
    {
        points.emplace_back(range.first, true);
        points.emplace_back(range.second + 1, false);
    }

    sort(points.begin(), points.end());

    int activeRanges = 0;
    int lastPoint = (int)(2e9 + 7);
    int count = 0;

    for (auto &point : points)
    {
        if (activeRanges > 0 && lastPoint != (int)(2e9 + 7))
        {
            count += point.first - lastPoint;
        }
        if (point.second)
        {
            activeRanges++;
        }
        else
        {
            activeRanges--;
        }
        lastPoint = point.first;
    }

    return min((int)nums.size(), count);
}

int main()
{
    vector<int> nums = {8, 8, 9};
    cout << maxDistinctElements(nums, 10) << endl; // Output: 7

    return 0;
}