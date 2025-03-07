class Solution
{
public:
    long long maximumCoins(vector<vector<int>> &coins, int k)
    {
        set<int> positions;
        map<int, int> comp;
        for (int i = 0; i < coins.size(); i++)
        {
            positions.insert(coins[i][0]), positions.insert(coins[i][1]);
        }
        int idx = 0;
        for (int pos : positions)
        {
            comp[pos] = idx++;
        }
        vector<long long> vals(idx, 0);
        for (int i = 0; i < coins.size(); i++)
        {
            int l = coins[i][0], r = coins[i][1], c = coins[i][2];
            vals[comp[l]] += c;
            if (comp[r] + 1 < idx)
            {
                vals[comp[r] + 1] -= c;
            }
        }
        for (int i = 1; i < idx; i++)
        {
            vals[i] += vals[i - 1];
        }

        long long ans = 0, cur = 0;
        map<int, long long> posCoins;
        for (int pos : positions)
        {
            posCoins[pos] = vals[comp[pos]];
        }
        auto it = posCoins.begin();
        deque<int> window;
        for (auto &[curPos, curCoins] : posCoins)
        {
            cur += curCoins;
            window.push_back(curPos);
            while (!window.empty() && window.back() - window.front() + 1 > k)
            {
                cur -= posCoins[window.front()];
                window.pop_front();
            }
            if (window.back() - window.front() + 1 == k)
            {
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};