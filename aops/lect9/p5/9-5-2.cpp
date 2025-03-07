#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

vector<int> sqr;
map<int, array<int, 2>> sums;
int three[3] = {INF, INF, INF}, four[4] = {INF, INF, INF, INF}, cur[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int curSqr = 0, diff = 1;
    while (curSqr < n)
    {
        curSqr += diff;
        diff += 2;
        sqr.pb(curSqr);
    }

    if (curSqr == n)
    {
        cout << n;
        exit(0);
    }

    for (int i = 0; i < sqr.size(); i++)
    {
        int x = sqr[i];
        for (int j = i; j < sqr.size(); j++)
        {
            int y = sqr[j];
            int sum = x + y;
            if (sum > n)
            {
                break;
            }
            if (sums.find(sum) == sums.end())
            {
                sums[sum] = {x, y};
            }
        }
    }

    if (sums.find(n) != sums.end())
    {
        cout << sums[n][0] << " " << sums[n][1];
        exit(0);
    }

    for (int s : sqr)
    {
        int tar = n - s;
        if (sums.find(tar) != sums.end())
        {
            cur[0] = min(s, sums[tar][0]), cur[2] = max(s, sums[tar][1]);
            cur[1] = n - cur[2] - cur[0];
            if (cur[0] < three[0] || cur[0] == three[0] && cur[1] < three[1])
            {
                three[0] = cur[0], three[1] = cur[1], three[2] = cur[2];
            }
        }
    }
    if (three[0] != INF)
    {
        cout << three[0] << " " << three[1] << " " << three[2];
        exit(0);
    }

    for (const auto &s : sums)
    {
        int tar = n - s.first;
        if (tar < s.first)
        {
            break;
        }
        if (sums.find(tar) != sums.end())
        {
            cur[0] = s.second[0], cur[1] = s.second[1], cur[2] = sums[tar][0], cur[3] = sums[tar][1];
            sort(cur, cur + 4);
            if (cur[0] < four[0] || cur[0] == four[0] && cur[1] < four[1] || cur[0] == four[0] && cur[1] == four[1] && cur[2] < four[2])
            {
                four[0] = cur[0], four[1] = cur[1], four[2] = cur[2], four[3] = cur[3];
            }
        }
    }
    cout << four[0] << " " << four[1] << " " << four[2] << " " << four[3];
}