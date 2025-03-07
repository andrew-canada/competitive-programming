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
        cin >> n >> a >> b >> s;
        array<int, 2> disp = {0, 0};
        bool found = false;
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
        cout << (found ? "YES\n" : "NO\n");
    }
}