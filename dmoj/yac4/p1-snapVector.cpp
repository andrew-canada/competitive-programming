#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int cardsPerPerson;
    cin >> cardsPerPerson;

    vector<int> cardList(2 * cardsPerPerson);
    fill(cardList.begin(), cardList.end(), 0);
    vector<int> sameIntCount(cardsPerPerson);
    fill(sameIntCount.begin(), sameIntCount.end(), 0);

    for (int i = 0; i < 2 * cardsPerPerson; i++)
    {
        cin >> cardList[i];
    }

    for (int i = 0; i < cardsPerPerson; i++)
    {
        for (int j = 0; j < cardsPerPerson; j++)
        {
            if (cardList[j] == cardList[j + cardsPerPerson])
            {
                sameIntCount[i] += 1;
            }
        }
        cardList.push_back(cardList[0]);
        cardList.erase(cardList.begin());
    }

    cout << *max_element(sameIntCount.begin(), sameIntCount.end());
}