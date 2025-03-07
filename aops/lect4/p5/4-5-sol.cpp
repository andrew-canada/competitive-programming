#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100
#define RANGE (100 * MAX_V + 1)

// Now these measure the current difference between the cow with the most
// and the cow with the least.
bool dp[2][RANGE];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int vals[n];
    int valsu = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> vals[i];
        valsu += vals[i];
    }
    for (int i = 0; i < RANGE; ++i)
    {
        dp[0][i] = false;
    }
    dp[0][0] = true;
    // swap this between 0 and 1 to indicate which row of array is active
    int which = 0;
    for (int k = 0; k < n; ++k)
    {
        int v = vals[k];
        for (int i = 0; i < RANGE; ++i)
        {
            dp[1 - which][i] = false;
        }
        for (int i = 0; i < RANGE; ++i)
        {
            if (dp[which][i])
            {
                // Option 1: give to leading cow, as long as the diff doesn't get
                // tooooo big
                if (i + v <= RANGE - 1)
                {
                    dp[1 - which][i + v] = true;
                }
                // Option 2: give to trailing cow
                if (v >= i)
                { // trailing cow now in the lead or tied
                    dp[1 - which][v - i] = true;
                }
                else
                { // trailing cow still trailing, but lead is smaller
                    dp[1 - which][i - v] = true;
                }
            }
        }
        which = 1 - which;
        for (int i = 0; i <= MAX_V; ++i)
        {
            if (dp[which][i])
            {
                cout << i << '\n';
                break;
            }
        }
    }
}