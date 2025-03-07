#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int i = s.find('0');
        if (i == -1)
        {
            cout << "1 " << s.size() << " 1 1\n";
            continue;
        }
        int j = i;
        while (j < s.size() && s[j] == '0')
        {
            j++;
        }
        int l = min(i, max(i - (j - i) + 1, 1));
        cout << "1 " << s.size() << ' ' << l << ' ' << l + s.size() - i - 1 << '\n';
    }
}