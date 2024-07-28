#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
int pts;
int quot, pn;

int main()
{
    scanf("%d", &n);
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            pts++;
            n /= 2;
        }
        else
        {
            quot = n / 2;
            if (quot % 2 == 0)
            {
                quot++;
            }
            while (quot >= 1)
            {
                pn = n - quot;
                if (pn % quot == 0)
                {
                    n = pn;
                    pts = pts + n / quot;
                    break;
                }
                quot -= 2;
            }
        }
    }
    printf("%d", pts);
}