#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, m;
    cin >> k >> m;
    vector<int> inv(k);
    for (int i = 0; i < k; i++)
    {
        inv[i] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int r;
        cin >> r;
        vector<int> newInv;
        for (int i = 1; i <= inv.size(); i++)
        {
            if (i % r != 0)
            {
                newInv.push_back(inv[i - 1]);
            }
        }
        inv = newInv;
    }
    for (int i : inv)
    {
        cout << i << '\n';
    }
}