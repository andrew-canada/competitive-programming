#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

const int mxN = 100;

int height[mxN + 1];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &height[i]);
    }
    sort(height, height + n);
    if (n % 2 == 0)
    {
        int offset = 1;
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            printf("%d %d ", height[i], height[i + offset]);
            offset += 2;
        }
    }
    else
    {
        int offset = 1;
        for (int i = n / 2; i > 0; i--)
        {
            printf("%d %d ", height[i], height[i + offset]);
            offset += 2;
        }
        printf("%d", height[0]);
    }
}