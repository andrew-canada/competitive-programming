#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

int t, g;
vector<int> score = {0, 0, 0, 0, 0};
vector<array<int, 2>> game = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

int calcWin(vector<array<int, 2>> rem, vector<int> curS, array<int, 2> cur = {0, 0}, int wlt = 3)
{
    if (wlt == -1)
    {
        curS[cur[1]] += 3;
    }
    else if (wlt == 0)
    {
        curS[cur[0]]++, curS[cur[1]]++;
    }
    else if (wlt == 1)
    {
        curS[cur[0]] += 3;
    }
    if (!rem.size())
    {
        for (int i = 1; i <= 4; i++)
        {
            if (i != t && curS[i] >= curS[t])
            {
                return 0;
            }
        }
        return 1;
    }
    int nw = 0;
    cur = rem.back();
    rem.pop_back();
    for (int i = -1; i <= 1; i++)
    {
        nw += calcWin(rem, curS, cur, i);
    }
    return nw;
}

int main()
{
    cin >> t >> g;
    int a, b, sa, sb;
    for (int i = 0; i < g; i++)
    {
        cin >> a >> b >> sa >> sb;
        if (sa > sb)
        {
            score[a] += 3;
        }
        else if (sb > sa)
        {
            score[b] += 3;
        }
        else
        {
            score[a]++, score[b]++;
        }
        for (int j = 0; j < 6; j++)
        {
            if (a == game[j][0] && b == game[j][1])
            {
                game.erase(game.begin() + j);
                break;
            }
        }
    }
    cout << calcWin(game, score);
}