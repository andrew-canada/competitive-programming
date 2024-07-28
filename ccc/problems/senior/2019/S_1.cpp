#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int h = 0, v = 0;
    for (char c : s)
    {
        if (c == 'H')
        {
            h++;
        }
        else
        {
            v++;
        }
    }
    if (h % 2 == 0)
    {
        if (v % 2 == 0)
        {
            cout << "1 2\n3 4";
        }
        else
        {
            cout << "2 1\n4 3";
        }
    }
    else
    {
        if (v % 2 == 0)
        {
            cout << "3 4\n1 2";
        }
        else
        {
            cout << "4 3\n2 1";
        }
    }
}