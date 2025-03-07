class Solution
{
public:
    int beautifulSplits(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                bool pref1 = true;
                for (int k = 0; k < i; k++)
                {
                    if (k >= j - i || nums[k] != nums[i + k])
                    {
                        pref1 = false;
                        break;
                    }
                }

                bool pref2 = true;
                for (int k = 0; k < j - i; k++)
                {
                    if (k >= n - j || nums[i + k] != nums[j + k])
                    {
                        pref2 = false;
                        break;
                    }
                }

                if (pref1 || pref2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};