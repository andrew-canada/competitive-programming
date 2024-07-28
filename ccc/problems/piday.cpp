#include <iostream>

using namespace std;

// max number
const int MN = 255;
int numPeople, totPies;
int dp[MN][MN][MN];

int main()
{
    cin >> numPeople >> totPies;
    // equivalent to each person gets one pie
    totPies -= numPeople;
    dp[0][0][0] = 1;

    for (int i = 0; i < numPeople; i++)
    {
        // <= to make sure it works if numPeople = totPies
        for (int j = 0; j <= totPies; j++)
        {
            for (int k = 0; k <= totPies; k++)
            {
                // l is number of pies for new person
                for (int l = k; l <= totPies; l++)
                {
                    dp[i + 1][j + l][l] += dp[i][j][k];
                }
            }
        }
    }
    // result
    int res = 0;
    for (int i = 0; i <= totPies; i++)
    {
        res += dp[numPeople][totPies][i];
    }
    cout << res << "\n";
}