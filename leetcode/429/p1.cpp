int maxDistinctElements(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<int> s;
    for (int i : nums)
    {

        for (int j = -k; j <= k; j++)
        {
            if (s.find(i + j) == s.end())
            {
                s.insert(i + j);
                break;
            }
        }
    }
    return s.size();
}

int maxDistinctElements(vector<int> &nums, int k)
{
    set<int> s(nums.begin(), nums.end());
    int dist = s.size();
    int tot = nums.size();
    int dup = tot - dist;
    return dist + min(dup, 2 * k);
}