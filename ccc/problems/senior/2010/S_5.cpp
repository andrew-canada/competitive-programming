#include <bits/stdc++.h>

using namespace std;

const int mxK = 1e4, mxX = 2500;

#define pb push_back

string tree;
string leaf;
int x;
int ans;
int dp[mxK + 1][mxX + 1];

int dfs(int n)
{
    if (tree[n])
    {
        for (int totG = 0; totG <= x; totG++)
        {
            for (int nodeG = 0; nodeG <= totG; nodeG++)
            {
                int edgeG = totG - nodeG;
                dp[n][totG] = max(dp[n][totG], nodeG + (1 + edgeG) * (1 + edgeG));
            }
        }
    }
    else
    {
        dfs(2 * n), dfs(2 * n + 1);
        for (int totG = 0; totG <= x; totG++)
        {
            for (int leftG = 0; leftG <= totG; leftG++)
            {
                int rightG = totG - leftG;
            }
        }
        for (int totG = 0; totG <= x; totG++)
        {
            for (int nodeG = 0; nodeG <= totG; nodeG++)
            {
                int edgeG = totG - nodeG;
                // dp[n][totG] = max(dp[n][totG], min());
            }
        }
    }
}

int main()
{
    getline(cin, leaf);
    cin >> x;
    if (leaf[0] != '(')
    {
        cout << x + stoi(leaf);
        return 0;
    }
    stack<string> s;
    int i = 1, n = 1;
    int l, r;
    while (!s.empty())
    {
        if (leaf[i] == ' ')
        {
            i++;
            continue;
        }
        if (leaf[i] == '(')
        {
            if (s.top() == "(")
            {
                n *= 2;
            }
            else
            {
                n = n * 2 + 1;
            }
            s.push("(");
            i++;
        }
        else if (leaf[i] == ')')
        {
            r = stoi(s.top());
            s.pop();
            l = stoi(s.top());
            s.pop();
            tree[2 * n] = l, tree[2 * n + 1] = r;
            i++;
            n /= 2;
            if (s.empty())
            {
                s.push("A");
            }
        }
        else
        {
            string nut = "";
            while (leaf[i] != '(' && leaf[i] != ')' && leaf[i] != ' ')
            {
                nut += leaf[i];
                i++;
            }
            s.push(nut);
        }
    }
    dfs(1);
    cout << ans;
}