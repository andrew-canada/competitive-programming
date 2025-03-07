#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        if (abs(a - b) & 1)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << '\n';
    }
}