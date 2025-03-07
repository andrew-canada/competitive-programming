#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int s = 0, c2 = 0, c3 = 0;
        for (char c : n)
        {
            int cs = c - '0';
            s += cs;
            if (cs == 2)
            {
                c2++;
            }
            if (cs == 3)
            {
                c3++;
            }
        }
        int val = (9 - (s % 9)) % 9;
        bool ok = false;
        for (int b = 0; b <= c3; b++)
        {
            int tmp = (val - 6 * b) % 9;
            if (tmp < 0)
            {
                tmp += 9;
            }
            int a = (tmp * 5) % 9;
            if (a <= c2)
            {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}