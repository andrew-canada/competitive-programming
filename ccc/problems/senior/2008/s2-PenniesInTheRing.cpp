#include <stdio.h>
#include <math.h>

int main()
{
    int radius = 0;
    int penniesInside = 0;
    scanf("%d", &radius);
    while (radius != 0)
    {
        for (int i = 0; i <= radius; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i * i + j * j <= radius * radius)
                {
                    penniesInside += 1;
                }
            }
        }
        printf("%d\n", penniesInside * 8 - 4 * radius - 7 - 4 * (int)(radius / sqrt(2.0)));
        scanf("%d", &radius);
        penniesInside = 0;
    }
}