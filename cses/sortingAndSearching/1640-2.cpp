#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (mp[x - a])
        {
            cout << i << " " << mp[x - a];
            return 0;
        }
        mp[a] = i;
    }
    cout << "IMPOSSIBLE\n";
}