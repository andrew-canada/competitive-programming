#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> value = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int main()
{
    string s;
    cin >> s;
    if (s.size() == 2)
    {
        cout << (s[0] - '0') * value[s[1]];
    }
    int ans = 0;
    for (int i = 0; i < s.length() - 2; i += 2)
    {
        if (value[s[i + 3]] > value[s[i + 1]])
        {
            ans -= (s[i] - '0') * value[s[i + 1]];
        }
        else
        {
            ans += (s[i] - '0') * value[s[i + 1]];
        }
    }
    cout << ans + (s[s.length() - 2] - '0') * value[s[s.length() - 1]];
}