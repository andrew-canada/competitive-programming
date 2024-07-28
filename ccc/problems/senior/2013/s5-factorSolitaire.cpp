#include <stdio.h>
#include <math.h>

int n;
int pts;

int main()
{
    scanf("%d", &n);
    int div;
    int prev;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            pts++;
        }
        else
        {
            div = n / 2;
            if (div % 2 == 0)
            {
                div += 1;
            }
            while (div >= 1)
            {
                prev = n - div;
                if (prev % div == 0)
                {
                    pts = pts + prev / div;
                    n = prev;
                    break;
                }
                div -= 2;
            }
        }
    }
    printf("%d", pts);
}