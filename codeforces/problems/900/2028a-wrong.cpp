/*
the additional conditions don't consider intermediates
just loop 20 times instead
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, a, b;
    string s;
    cin >> t;
    while (t--)
    {
        array<int, 2> disp = {0, 0};
        bool found = false;
        cin >> n >> a >> b >> s;
        if (a == 0 && b == 0)
        {
            cout << "YES\n";
            continue;
        }
        for (char c : s)
        {
            if (c == 'N')
            {
                disp[1]++;
            }
            else if (c == 'E')
            {
                disp[0]++;
            }
            else if (c == 'S')
            {
                disp[1]--;
            }
            else
            {
                disp[0]--;
            }
            if (disp[0] == a && disp[1] == b)
            {
                found = true;
                break;
            }
        }
        if (a == 0 && disp[1] <= 0)
        {
            found = false;
        }
        else if (b == 0 && disp[0] <= 0)
        {
            found = false;
        }
        else if (disp[0] >= 1 && disp[1] >= 1)
        {
            for (int i = 0; i < 20; i++)
            {
                for (char c : s)
                {
                    if (c == 'N')
                    {
                        disp[1]++;
                    }
                    else if (c == 'E')
                    {
                        disp[0]++;
                    }
                    else if (c == 'S')
                    {
                        disp[1]--;
                    }
                    else
                    {
                        disp[0]--;
                    }
                    if (disp[0] == a && disp[1] == b)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    break;
                }
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}