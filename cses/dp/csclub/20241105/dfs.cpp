#include <bits/stdc++.h>

using namespace std;

int tree[17] = {0, 2, 7, 5, 2, 6, 9, 0, 0, 0, 5, 11, 4};

void dfs(int i)
{
    if (i > 16)
    {
        return;
    }
    cout << i << ": " << tree[i] << '\n';
    dfs(i * 2);
    dfs(i * 2 + 1);
}

int main()
{
    dfs(1);
}