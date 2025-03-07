#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(string str, int k)
    {
        int n = 0, s = 0, e = 0, w = 0, ans = 0;
        for (char c : str)
        {
            if (c == 'N')
            {
                n++;
            }
            else if (c == 'S')
            {
                s++;
            }
            else if (c == 'E')
            {
                e++;
            }
            else
            {
                w++;
            }
            int maxY = max(n, s), minY = min(n, s), maxX = max(e, w), minX = min(e, w);
            int ops = min(minY + minX, k);
            ans = max(ans, maxY - minY + maxX - minX + 2 * ops);
        }
        return ans;
    }
};