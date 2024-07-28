#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

bool isPrime(int a)
{
    REP(i, 2, sqrt(a))
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    int sum;
    int j;
    while (t--)
    {
        scanf("%d", &n);
        sum = 2 * n;
        REP(i, 2, n)
        {
            if (isPrime(i))
            {
                j = sum - i;
                if (isPrime(j))
                {
                    printf("%d %d\n", i, j);
                    break;
                }
            }
        }
    }
}