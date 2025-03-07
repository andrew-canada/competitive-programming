#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumIncrements(vector<int> &nums, vector<int> &target)
    {
        int ans = 0;
        for (int t : target)
        {
            int cur = 0x3f3f3f3f, curIdx, curVal;
            for (int idx = 0; idx < nums.size(); idx++)
            {
                int n = nums[idx];
                if (n % t == 0)
                {
                    cur = 0;
                    curIdx = idx;
                    curVal = n;
                    break;
                }
                else if (n < t)
                {
                    if (t - n < cur)
                    {
                        cur = t - n;
                        curIdx = idx;
                        curVal = t;
                    }
                }
                else
                {
                    int i;
                    for (i = 2; true; i++)
                    {
                        if (t * i > n)
                        {
                            break;
                        }
                    }
                    cur = min(cur, t * i - n);
                    if (t * i - n < cur)
                    {
                        cur = t * i - n;
                        curIdx = idx;
                        curVal = t * i;
                    }
                }
            }
            ans += cur;
            nums[curIdx] = curVal;
        }
        return ans;
    }
};