#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    //  cin.tie(0);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "1\n";
        }
        else if (n == 2)
        {
            cout << "2\n";
        }
        else if (n == 3)
        {
            cout << "3\n";
        }
        else
        {
            int g = n / 3;
            int rem;
            if (n % 3 == 0)
            {
                rem = n - (max(g - 1, 0) * 3 + 1);
            }
            else
            {
                rem = n - g * 3;
            }
            cout << g + rem << '\n';
        }
    }
}