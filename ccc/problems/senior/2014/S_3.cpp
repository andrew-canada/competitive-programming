#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 1e5;
int car[mxN + 1];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &car[i]);
        }
        int need = 1;
        s.push(INF);
        for (int i = n - 1; i >= 0; i--)
        {
            int cur = car[i];
            if (cur == need)
            {
                need++;
            }
            else
            {
                while (!s.empty())
                {
                    if (s.top() == need)
                    {
                        need++;
                        s.pop();
                    }
                    else
                    {
                        s.push(cur);
                        break;
                    }
                }
            }
        }
        while (!s.empty() && s.top() == need)
        {
            s.pop();
            need++;
        }
        if (need == n + 1)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
}

/*
1
4
2
3
1
4
*/