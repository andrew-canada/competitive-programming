#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a1, a2, a4, a5;
    cin >> t;
    while (t--)
    {
        cin >> a1 >> a2 >> a4 >> a5;
        set<int> s;
        s.insert(a1 + a2), s.insert(a4 - a2), s.insert(a5 - a4);
        cout << 4 - s.size() << '\n';
    }
}