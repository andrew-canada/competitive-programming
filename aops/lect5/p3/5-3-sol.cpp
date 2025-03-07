#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    vector<set<int>> neighs;
    for (int i = 0; i < n; ++i)
    {
        set<int> s;
        neighs.push_back(s);
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> x;
        x--;
        neighs[i].insert(x);
        neighs[x].insert(i);
    }
    queue<int> leaves;
    for (int i = 0; i < n; ++i)
    {
        if (neighs[i].size() == 1)
        {
            leaves.push(i);
        }
    }
    int score = 0;
    while (!leaves.empty())
    {
        int curr_leaf = leaves.front();
        leaves.pop();
        if (neighs[curr_leaf].size() != 1)
        { // not actually a leaf
            continue;
        }
        score++;
        int parent;
        // janky way of getting the single element out of the set
        for (int x : neighs[curr_leaf])
        {
            parent = x;
            break;
        }
        // this vector exists so we don't iterate over something we're deleting
        // from
        vector<int> to_delete;
        for (int x : neighs[parent])
        {
            to_delete.push_back(x);
        }
        for (int x : to_delete)
        {
            neighs[parent].erase(x);
            neighs[x].erase(parent);
            if (neighs[x].size() == 1)
            {
                leaves.push(x);
            }
        }
    }
    cout << score << '\n';
}