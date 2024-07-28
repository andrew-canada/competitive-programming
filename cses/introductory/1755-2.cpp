#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int freq[200];

int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        freq[c]++;
    }
    int no = 0;
    char oc;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (freq[i] & 1)
        {
            no++;
            oc = i;
        }
    }
    if (no > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (freq[i] & 1 ^ 1)
        {
            for (int j = 0; j < freq[i] / 2; j++)
            {
                cout << char(i);
            }
        }
    }
    for (int i = 0; i < freq[oc]; i++)
    {
        cout << oc;
    }
    for (int i = 'Z'; i >= 'A'; i--)
    {
        if (freq[i] & 1 ^ 1)
        {
            for (int j = 0; j < freq[i] / 2; j++)
            {
                cout << char(i);
            }
        }
    }
}