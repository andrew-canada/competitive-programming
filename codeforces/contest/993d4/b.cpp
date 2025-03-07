#include <bits/stdc++.h>

using namespace std;

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
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'p')
            {
                cout << 'q';
            }
            else if (s[i] == 'q')
            {
                cout << 'p';
            }
            else
            {
                cout << 'w';
            }
        }
        cout << '\n';
    }
}