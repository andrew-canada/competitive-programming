#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool found = false;
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == s[i + 1])
            {
                found = true;
                break;
            }
        }
        cout << (found ? 1 : s.size()) << '\n';
    }
}