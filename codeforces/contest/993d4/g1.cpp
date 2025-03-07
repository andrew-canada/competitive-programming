#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
            r[i]--;
        }

        vector<int> plushies(n, 1);
        vector<int> next_plushies(n, 0);
        int year = 2;

        while (true)
        {
            fill(next_plushies.begin(), next_plushies.end(), 0);
            for (int i = 0; i < n; i++)
            {
                if (plushies[i] > 0)
                {
                    next_plushies[r[i]]++;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (next_plushies[i] > 1)
                {
                    next_plushies[i] = 1;
                }
            }
            if (next_plushies == plushies)
            {
                cout << year << '\n';
                break;
            }
            plushies = next_plushies;
            year++;
        }
    }
}