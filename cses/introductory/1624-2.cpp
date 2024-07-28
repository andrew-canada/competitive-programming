#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s[8];
int coord[8];
bool queen[15];

int main()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }
    iota(coord, coord + 8, 0);
    int ans = 0;
    do
    {
        bool safe = true;
        for (int i = 0; i < 8; i++)
        {
            safe &= s[i][coord[i]] == '.';
        }
        memset(queen, 0, sizeof(queen));
        for (int i = 0; i < 8; i++)
        {
            if (queen[i + coord[i]])
            {
                safe = false;
            }
            queen[i + coord[i]] = true;
        }
        memset(queen, 0, sizeof(queen));
        for (int i = 0; i < 8; i++)
        {
            if (queen[i + 7 - coord[i]])
            {
                safe = false;
            }
            queen[i + 7 - coord[i]] = true;
        }
        ans += safe;
    } while (next_permutation(coord, coord + 8));
    cout << ans;
}