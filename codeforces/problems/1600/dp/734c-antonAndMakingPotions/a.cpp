#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        vector<int> ans(numberOfUsers);
        vector<int> users(numberOfUsers);
        for (int i = 0; i < numberOfUsers; i++)
        {
            users[i] = -1;
        }
        for (const vector<string> &e : events)
        {
            if (e[0] == "MESSAGE")
            {
                stringstream ss1(e[2]);
                string cur1;
                vector<string> mentions;
                while (ss1 >> cur1)
                {
                    mentions.push_back(cur1);
                }
                stringstream ss2(e[1]);
                string cur2;
                vector<int> times;
                while (ss2 >> cur2)
                {
                    times.push_back(stoi(cur2));
                }

                for (int i = 0; i < mentions.size(); i++)
                {
                    if (mentions[i] == "ALL")
                    {
                        for (int j = 0; j < numberOfUsers; j++)
                        {
                            ans[j]++;
                        }
                    }
                    else if (mentions[i] == "HERE")
                    {
                        for (int j = 0; j < numberOfUsers; j++)
                        {
                            if (users[j] <= times[i])
                            {
                                ans[j]++;
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < numberOfUsers; j++)
                        {
                            if (users[stoi(mentions[j].substr(2, mentions[j].size() - 2))] <= times[i])
                            {
                                ans[stoi(mentions[j].substr(2, mentions[j].size() - 2))]++;
                            }
                        }
                    }
                }
            }
            else
            {
                stringstream ss1(e[2]);
                string cur1;
                vector<string> mentions;
                while (ss1 >> cur1)
                {
                    mentions.push_back(cur1);
                }
                stringstream ss2(e[1]);
                string cur2;
                vector<int> times;
                while (ss2 >> cur2)
                {
                    times.push_back(stoi(cur2));
                }

                for (int i = 0; i < mentions.size(); i++)
                {
                    users[stoi(mentions[i])] = times[i] + 60;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int numberOfUsers = 2;
    vector<vector<string>> events = {
        {"MESSAGE", "10", "id1 id0"},
        {"OFFLINE", "11", "0"},
        {"MESSAGE", "71", "HERE"}};

    vector<int> result = sol.countMentions(numberOfUsers, events);
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;
}