// n columns of pixels of height Hn
// peak is higher than left and right
// result only has one peak
// (i, j, k) -> peak j increments for cost Hi+Hj+Hk
// minimize cost to create single peak

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back

const int MAXN = 1000005;
int finalHeight[MAXN];
int currentHeight[MAXN];
pii minPos[MAXN];
int cost;
int minVal;
int maxVal = -1;
int maxIdx;

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &currentHeight[i]);
        minPos[i] = {currentHeight[i], i};
        if (currentHeight[i] > maxVal)
        {
            maxVal = currentHeight[i];
            maxIdx = i;
        }
    }
    REP(i, 1, maxIdx - 1)
    {
        finalHeight[i] = max(finalHeight[i - 1], currentHeight[i]);
    }
    for (int i = n; i > maxIdx; i--)
    {
        finalHeight[i] = max(finalHeight[i + 1], currentHeight[i]);
    }

    while (true)
    {
        sort(minPos + 1, minPos + 1 + n);
        int first, last;
        int curH, curIdx;
        int numH;
        vector<int> valley;
        int minValley;
        REP(i, 1, n)
        {
            if (minPos[i].first < finalHeight[minPos[i].second])
            {
                minValley = minPos[i].first;
                break;
            }
        }
        REP(i, 1, n)
        {
            if (minPos[i].first > minValley)
            {
                break;
            }
            if (minPos[i].first == minValley)
            {
                if (minPos[i].first < finalHeight[minPos[i].second])
                {
                    valley.pb(i);
                }
            }
        }
        if (valley.size() == 0)
        {
            break;
        }
        if (valley.size() == 1)
        {
            int minVal = minPos[valley[0]].first;
            int minIdx = minPos[valley[0]].second;
            int idx1, idx2;
            REP(i, valley[0] + 1, n)
            {
                if (minPos[i].first > minVal && minPos[i].second > minIdx)
                {
                    idx1 = i;
                    break;
                }
            }
            REP(i, valley[0] + 1, n)
            {
                if (minPos[i].first > minVal && minPos[i].second < minIdx)
                {
                    idx2 = i;
                    break;
                }
            }
            cost += minPos[idx1].first + minVal + minPos[idx2].first;
            minPos[valley[0]].first++;
            currentHeight[minPos[valley[0]].second]++;
        }
        else
        {
            first = valley.front(), last = valley.back();
            curH = minPos[first].first;
            int lv, rv, mv;
            REP(i, 1, first - 1)
            {
                if (minPos[i].first > curH && minPos[i].second < minPos[first].second)
                {
                    lv = minPos[i].first;
                    break;
                }
            }
            REP(i, last + 1, n)
            {
                if (minPos[i].first > curH && minPos[i].second > minPos[last].second)
                {
                    rv = minPos[i].first;
                    break;
                }
            }
            if (lv >= rv)
            {
                REP(i, first, n)
                {
                    if (minPos[i].first > minPos[first].first && minPos[i].second > minPos[last].second)
                    {
                        cost += lv + minPos[first].first + minPos[i].first;
                        cost += (minPos[first].first + 1) + minPos[last].first + rv;
                        break;
                    }
                }
            }
            else
            {
                REP(i, first, n)
                {
                    if (minPos[i].first > minPos[last].first && minPos[i].second < minPos[first].second)
                    {
                        cost += minPos[i].first + minPos[last].first + rv;
                        cost += lv + minPos[first].first + (minPos[last].first + 1);
                        break;
                    }
                }
            }
            cost += (valley.size() - 2) * (minPos[first].first + 2 * (minPos[first].first + 1));
            for (int i : valley)
            {
                if (minPos[i].first + 1 == finalHeight[minPos[i].second])
                {
                    minPos[i].first = INF;
                    currentHeight[minPos[i].second] = INF;
                }
                else
                {
                    minPos[i].first++;
                    currentHeight[minPos[i].second]++;
                }
            }
        }
    }
    printf("%d", cost);
}