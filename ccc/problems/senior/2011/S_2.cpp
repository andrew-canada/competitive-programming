#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e4;

char corr[mxN + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &corr[i]);
    }
    int ans = 0;
    char c;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &c);
        if (c == corr[i])
        {
            ans++;
        }
    }
    printf("%d", ans);
}