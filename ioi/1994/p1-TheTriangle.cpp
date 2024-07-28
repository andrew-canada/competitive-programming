#include <stdio.h>

int triangle[102][102];
int answer[102][102];

#define max(a, b) ((a > b) ? a : b)
//#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int triangleHeight = 0;
    scanf("%d", &triangleHeight);

    for (int i = 0; i < triangleHeight; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &triangle[i][j]);
        }
    }

    for (int i = triangleHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            answer[i][j] = triangle[i][j] + max(answer[i + 1][j], answer[i + 1][j + 1]);
        }
    }

    printf("%d", answer[0][0]);
}