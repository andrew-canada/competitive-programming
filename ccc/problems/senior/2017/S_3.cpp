#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int mxN = 1e6;
int height[mxN + 1];
int freq[4005];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d", &height[i]);
        freq[height[i]]++;
    }
    int maxLen = -1, numHeight = 0;
    REP(h, 0, 4000)
    {
        int curLen = 0;
        REP(w1, 1, h / 2)
        {
            int w2 = h - w1;
            if (!freq[w1] || !freq[w2])
            {
                continue;
            }
            if (w1 == w2)
            {
                curLen += freq[w1] / 2;
            }
            else
            {
                int numFence = min(freq[w1], freq[w2]);
                curLen += numFence;
            }
        }
        if (curLen > maxLen)
        {
            maxLen = curLen;
            numHeight = 1;
        }
        else if (curLen == maxLen)
        {
            numHeight++;
        }
    }
    printf("%d %d\n", maxLen, numHeight);
}