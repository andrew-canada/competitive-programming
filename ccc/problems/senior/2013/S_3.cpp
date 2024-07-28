#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

vector<array<int, 2>> game = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
int t, g;
vector<int> score = {0, 0, 0, 0, 0};

int numW(int res, vector<int> curS, array<int, 2> curG, vector<array<int, 2>> remG)
{
    if (res == -1)
    {
        curS[curG[1]] += 3;
    }
    else if (res == 0)
    {
        curS[curG[0]]++;
        curS[curG[1]]++;
    }
    else if (res == 1)
    {
        curS[curG[0]] += 3;
    }
    if (remG.empty())
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
    int totW = 0;
    curG = remG.back();
    remG.pop_back();
    for (int i = -1; i <= 1; i++)
    {
        totW += numW(i, curS, curG, remG);
    }
    return totW;
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
            score[a]++;
            score[b]++;
        }
        for (int j = 0; j < 6; j++)
        {
            if (game[j][0] == a && game[j][1] == b)
            {
                game.erase(game.begin() + j);
                break;
            }
        }
    }
    cout << numW(INF, score, {0, 0}, game);
}