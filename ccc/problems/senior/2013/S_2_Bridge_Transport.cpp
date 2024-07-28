#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int w, n;
int t[100005];
int bw;

int main()
{
    scanf("%d%d", &w, &n);
    REP(i, 4, n + 4)
    {
        scanf("%d", &t[i]);
        bw = bw + t[i] - t[i - 4];
        if (bw > w)
        {
            printf("%d", i - 4);
            return 0;
        }
    }
    printf("%d", n);
}