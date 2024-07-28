#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int numT = 0, numS = 0;
    getline(cin, s);
    while (n--)
    {
        getline(cin, s);
        for (char c : s)
        {
            if (c == 't' || c == 'T')
            {
                numT++;
            }
            else if (c == 's' || c == 'S')
            {
                numS++;
            }
        }
    }
    if (numT > numS)
    {
        cout << "English";
    }
    else
    {
        cout << "French";
    }
}