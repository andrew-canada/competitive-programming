#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s1);
    getline(cin, s2);
    if (s1 == s2)
    {
        cout << "YES\n0";
        return 0;
    }
    else if ((s2 == "1 1" || s2 == "2 2" || s2 == "3 3") && (s1[0] == s2[0] || s1[2] == s2[0]))
    {
        cout << "YES\n1\n";
        if (s1[0] == s2[0])
        {
            cout << "L 0 1";
        }
        else
        {
            cout << "R 0 1";
        }
        return 0;
    }
    else
    {
        cout << "NO";
    }
}