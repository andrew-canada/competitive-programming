#include <bits/stdc++.h>
using namespace std;

string encode(vector<string> &strs)
{
    string ans = "";
    for (string s : strs)
    {
        ans += s + '|';
    }
    return ans;
}

vector<string> decode(string s)
{
    vector<string> ans;
    int cur = 0, prev = 0;
    while (cur < s.size())
    {
        while (s[cur] != '|' && cur < s.size())
        {
            cur++;
        }
        ans.push_back(s.substr(prev, cur - prev + 1));
        cur++;
        prev = cur;
    }
    return ans;
}

int main()
{
    vector<string> v = {"neet", "code", "love", "you"};
    string s = encode(v);
    vector<string> res = decode(s);
}