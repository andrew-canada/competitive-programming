#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int cardsPerPerson;
    cin >> cardsPerPerson;

    int *cardList = new int[2 * cardsPerPerson + cardsPerPerson]{0};
    int *sameIntCount = new int[cardsPerPerson]{0};

    for (int i = 0; i < 2 * cardsPerPerson; i++)
    {
        cin >> cardList[i];
    }

    int j = 0;
    for (int i = 0; i < cardsPerPerson; i++)
    {
        for (j; j < cardsPerPerson; j++)
        {
            if (cardList[j] == cardList[j + cardsPerPerson])
            {
                sameIntCount[i] += 1;
            }
        }
        j -= cardsPerPerson + 2;
        cardList[2 * cardsPerPerson + i] = cardList[i];
    }

    cout << *max_element(sameIntCount, sameIntCount + cardsPerPerson);
}