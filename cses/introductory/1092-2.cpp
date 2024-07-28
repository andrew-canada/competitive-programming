#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    if ((n * (n + 1) / 2) & 1)
    {
        cout << "NO";
        return 0;
    }
    vector<int> s1, s2;
    int offset;
    if (n & 1)
    {
        offset = 3;
    }
    else
    {
        offset = 4;
    }
    for (int i = 0; i < (n - 1) / 4; i++)
    {
        s1.pb(i * 4 + 1 + offset), s1.pb(i * 4 + 4 + offset);
        s2.pb(i * 4 + 2 + offset), s2.pb(i * 4 + 3 + offset);
    }
    if (n & 1)
    {
        s1.pb(1), s1.pb(2);
        s2.pb(3);
    }
    else
    {
        s1.pb(1), s1.pb(4);
        s2.pb(2), s2.pb(3);
    }

    cout << "YES\n";
    cout << s1.size() << '\n';
    for (int i : s1)
    {
        cout << i << " ";
    }
    cout << '\n';
    cout << s2.size() << '\n';
    for (int i : s2)
    {
        cout << i << " ";
    }
}