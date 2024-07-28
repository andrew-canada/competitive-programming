#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

multiset<int> h;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int p;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        h.insert(p);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        auto it = h.upper_bound(p);
        if (it == h.begin())
        {
            cout << "-1\n";
        }
        else
        {
            cout << *(--it) << '\n';
            h.erase(it);
        }
    }
}