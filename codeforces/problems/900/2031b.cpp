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
        vector<int> p(n + 1);
        bool found = true;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n - 1; i++)
        {
            if (p[i] == i)
            {
                continue;
            }
            else if (p[i] == i + 1 && p[i + 1] == i)
            {
                swap(p[i], p[i + 1]);
            }
            else
            {
                found = false;
                break;
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}