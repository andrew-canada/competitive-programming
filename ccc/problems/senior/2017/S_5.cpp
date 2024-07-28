#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int mxN = 15e4;

int stnLn[mxN + 1];
int numP[mxN + 1];
unordered_map<int, vector<int>> line;

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    REP(i, 0, n - 1)
    {
        scanf("%d", &stnLn[i]);
    }
    REP(i, 0, n - 1)
    {
        scanf("%d", &numP[i]);
        line[stnLn[i]].push_back(numP[i]);
    }
    int type;
    REP(i, 0, q - 1)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int sum = 0;
            REP(j, l, r)
            {
                sum += numP[j];
            }
            printf("%d\n", sum);
        }
        else
        {
            int x;
            scanf("%d", &x);
            line[0] = line[line[x].size() - 1];
            for (int j = line[x].size() - 1; j >= 0; j--)
            {
                line[j] = line[j - 1];
            }
        }
    }
}