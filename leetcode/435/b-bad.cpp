#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        map<char, int> mp;
        mp['N'] = mp['S'] = mp['E'] = mp['W'] = 0;
        int dy = 0, dx = 0, ans = 0;
        for (char c : s)
        {
            if (c == 'N')
            {
                mp['N']++;
                dy++;
            }
            else if (c == 'S')
            {
                mp['S']++;
                dy--;
            }
            else if (c == 'E')
            {
                mp['E']++;
                dx++;
            }
            else
            {
                mp['W']++;
                dx--;
            }
        }
        if (abs(dx) > abs(dy))
        {
            if (dx > 0)
            {
                while (mp['W'] && k)
                {
                    mp['W']--;
                    k--;
                }
            }
            else
            {
                while (mp['E'] && k)
                {
                    mp['E']--;
                    k--;
                }
            }
            ans = max(ans, abs(mp['N'] - mp['S']) + abs(mp['E'] - mp['W']));
            if (dy > 0)
            {
                while (mp['S'] && k)
                {
                    mp['S']--;
                    k--;
                }
            }
            else
            {
                while (mp['N'] && k)
                {
                    mp['N']--;
                    k--;
                }
            }
            ans = max(ans, abs(mp['N'] - mp['S']) + abs(mp['E'] - mp['W']));
        }
        else
        {
            if (dy > 0)
            {
                while (mp['S'] && k)
                {
                    mp['S']--;
                    k--;
                }
            }
            else
            {
                while (mp['N'] && k)
                {
                    mp['N']--;
                    k--;
                }
            }
            ans = max(ans, abs(mp['N'] - mp['S']) + abs(mp['E'] - mp['W']));
            if (dx > 0)
            {
                while (mp['W'] && k)
                {
                    mp['W']--;
                    k--;
                }
            }
            else
            {
                while (mp['E'] && k)
                {
                    mp['E']--;
                    k--;
                }
            }
            ans = max(ans, abs(mp['N'] - mp['S']) + abs(mp['E'] - mp['W']));
        }
        return ans;
    }
};