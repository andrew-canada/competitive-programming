#include <bits/stdc++.h>

using namespace std;

int f1[200], f2[200];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (char c : s1)
    {
        f1[c - 'a']++;
    }
    for (char c : s2)
    {
        f2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (f2[i] > f1[i])
        {
            cout << "N\n";
            return 0;
        }
    }
    cout << "A\n";
}