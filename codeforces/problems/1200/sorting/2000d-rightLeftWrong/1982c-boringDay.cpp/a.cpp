#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxWeight(vector<int> &pizzas)
    {
        int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        int l = 0, r = n - 1, day = 1;
        long long ans = 0;
        while (l < r)
        {
            if (day & 1)
            {
                ans += pizzas[r];
                l += 3, --r;
            }
            else
            {
                if (r - l > 4 && pizzas[r] != pizzas[r - 1])
                {
                    ans += pizzas[r] - pizzas[r - 1];
                }
                ans += pizzas[r - 1];
                l += 2, r -= 2;
            }
            ++day;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> pizzas = {4, 2, 1, 5, 2, 5, 5, 4, 2, 3, 2, 1};
    cout << sol.maxWeight(pizzas) << '\n';
}
