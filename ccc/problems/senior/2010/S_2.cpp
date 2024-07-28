#include <bits/stdc++.h>

using namespace std;

unordered_map<string, char> stc;

int main()
{
    int k;
    char c;
    string s;
    vector<string> seq;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> c >> s;
        seq.push_back(s);
        stc[s] = c;
    }
    cin >> s;
    while (s.size())
    {
        for (string str : seq)
        {
            if (s.find(str) == 0)
            {
                cout << stc[str];
                s = s.substr(str.size());
            }
        }
    }
}