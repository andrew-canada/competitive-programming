#include <bits/stdc++.h>

using namespace std;

string name[31];
unordered_map<string, string> group;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    string cur;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (cur == name[i])
        {
            cout << "bad";
            return 0;
        }
        group[cur] = name[i];
        group[name[i]] = cur;
    }
    for (int i = 0; i < n; i++)
    {
        if (name[i] != group[group[name[i]]])
        {
            cout << "bad";
            return 0;
        }
    }
    cout << "good";
}