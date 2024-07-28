#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;

int t, g;
int a, b, sa, sb;
vector<int> scores = {0, 0, 0, 0, 0};
vector<pii> games = {make_pair(1, 2), make_pair(1, 3), make_pair(1, 4), make_pair(2, 3), make_pair(2, 4), make_pair(3, 4)};

int calcWins(vector<pii> remGames, vector<int> curScores, pii curGame, int gameState);

int main()
{
    scanf("%d%d", &t, &g);
    while (g--)
    {
        scanf("%d%d%d%d", &a, &b, &sa, &sb);
        if (sa > sb)
        {
            scores[a] += 3;
        }
        else if (sb > sa)
        {
            scores[b] += 3;
        }
        else
        {
            scores[a]++;
            scores[b]++;
        }

        pii curTeams = make_pair(a, b);
        REP(i, 0, 6)
        {
            if (games[i] == curTeams)
            {
                games.erase(games.begin() + i);
                break;
            }
        }
    }
    printf("%d", calcWins(games, scores, make_pair(0, 0), 2));
}

int calcWins(vector<pii> remGames, vector<int> curScores, pii curGame, int gameState)
{
    if (gameState == -1)
    {
        curScores[curGame.second] += 3;
    }
    if (gameState == 0)
    {
        curScores[curGame.first]++;
        curScores[curGame.second]++;
    }
    if (gameState == 1)
    {
        curScores[curGame.first] += 3;
    }
    if (remGames.empty())
    {
        REP(i, 1, 5)
        {
            if (i != t && curScores[i] >= curScores[t])
            {
                return 0;
            }
        }
        return 1;
    }
    curGame = remGames.back();
    remGames.pop_back();
    int numWins = 0;
    REP(i, -1, 2)
    {
        numWins += calcWins(remGames, curScores, curGame, i);
    }
    return numWins;
}