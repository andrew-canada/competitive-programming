#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "1\n";
        }
        else if (n == 2 || n == 3 || n == 4)
        {
            cout << "2\n";
        }
        else
        {
            int ans = 2, tot = 4;
            while (true)
            {
                int next = 2 * (tot + 1);
                if (next < n)
                {
                    ans += 1;
                    tot = next;
                }
                else if (next >= n)
                {
                    ans += 1;
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
}