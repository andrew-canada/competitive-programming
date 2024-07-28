#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int cardsPerPerson;
    scanf("%d", &cardsPerPerson);

    int *cardList = new int[2 * cardsPerPerson]{0};
    int *sameIntCount = new int[cardsPerPerson]{0};

    for (int i = 0; i < 2 * cardsPerPerson - 1; i++)
    {
        scanf("%d ", &cardList[i]);
    }
    scanf("%d", &cardList[2 * cardsPerPerson - 1]);

    int j = 0;
    for (int i = 0; i < cardsPerPerson; i++)
    {
        for (j; j < cardsPerPerson; j++)
        {
            if (j + cardsPerPerson == 2 * cardsPerPerson)
            {
                j = 0;
            }
            if (cardList[j] == cardList[j + cardsPerPerson])
            {
                sameIntCount[i] += 1;
            }
        }
    }

    printf("%d", *max_element(sameIntCount, sameIntCount + cardsPerPerson));
}