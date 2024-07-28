#include <stdio.h>

//#define LOCAL

#define min(a, b) ((a < b) ? a : b)

int answer[5285];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int distToHole, numClubs;
    int currentClub;

    scanf("%d\n%d", &distToHole, &numClubs);

    for (int i = 1; i <= distToHole; i++)
    {
        answer[i] = 1000;
    }
    for (int i = 0; i < numClubs; i++)
    {
        scanf("%d", &currentClub);
        answer[currentClub] = 1;
    }
    for (int i = 1; i <= distToHole; i++)
    {
        for (int j = 1; j < i; j++)
        {
            answer[i] = min(answer[i], answer[j] + answer[i - j]);
        }
    }

    if (answer[distToHole] != 1000)
    {
        printf("%s %d %s", "Roberta wins in", answer[distToHole], "strokes.");
    }
    else
    {
        printf("%s", "Roberta acknowledges defeat.");
    }
}