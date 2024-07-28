#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

int t, g;
int a, b, sa, sb;
vi scores = {0, 0, 0, 0, 0};
vpii games = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
int w;

int cnw(vpii curG, pii cg, vi curS, int status)
{
    if (status == 1)
    {
        curS[cg.first] += 3;
    }
    else if (status == -1)
    {
        curS[cg.second] += 3;
    }
    else if (status == 0)
    {
        curS[cg.first]++;
        curS[cg.second]++;
    }
    if (curG.empty())
    {
        REP(i, 1, 5)
        {
            if (curS[i] >= curS[t] && i != t)
            {
                return 0;
            }
        }
        return 1;
    }
    cg = curG.back();
    curG.pop_back();
    int nw = 0;
    REP(i, -1, 2)
    {
        nw += cnw(curG, cg, curS, i);
    }
    return nw;
}

int main()
{
    scanf("%d%d", &t, &g);
    REP(i, 0, g)
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
        REP(i, 0, 6)
        {
            if (games[i].first == a && games[i].second == b)
            {
                games.erase(games.begin() + i);
                break;
            }
        }
    }
    printf("%d", cnw(games, {0, 0}, scores, 2));
}
