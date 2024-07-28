#include <stdio.h>

typedef long long ll;

int main()
{
    ll x;
    scanf("%d", &x);
    ll i = x - 1;
    do
    {
        if ((x + i) % 2 == 0)
        {
            printf("%d", (x + i) / 2);
            return 0;
        }
        i -= 1;
    } while (i >= 0);
}