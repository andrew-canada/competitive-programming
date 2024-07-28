#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int y;
int len;
bool dist;

int main()
{
    scanf("%d", &y);
    while (true)
    {
        dist = true;
        y += 1;
        string sy(to_string(y));
        len = sy.size();
        REP(i, 0, sy.size() - 1)
        {
            REP(j, i + 1, sy.size())
            {
                if (sy[i] == sy[j])
                {
                    dist = 0;
                    break;
                }
            }
        }
        if (dist)
        {
            printf("%d", y);
            break;
        }
    }
}