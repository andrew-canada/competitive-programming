/*
1:23
1:09
0:20
*/

#include <bits/stdc++.h>

using namespace std;

string answerString(string word, int numFriends)
{
    int len = word.size() - numFriends + 1;
    string sorted = word;
    sort(sorted.begin(), sorted.end(), greater<int>());
    char greatest = sorted[0];
    string ans = "1", cur = "1";
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == greatest)
        {
            cur = word.substr(i, min(len, (int)word.size() - i));
            cout << len << " " << word.size() - i << '\n';
            if (cur > ans)
            {
                ans = cur;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << answerString("gh", 1) << '\n';
    cout << ("h" > "gh");
}