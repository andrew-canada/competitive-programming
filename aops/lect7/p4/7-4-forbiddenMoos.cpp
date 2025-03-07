#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char tree[1 << 27];

char getState(char l, char r)
{
    if (l == 'f' && r == 'f')
    {
        return 'l';
    }
    else if (l == 'f')
    {
        return (r == 'l' ? 'w' : 'l');
    }
    else if (r == 'f')
    {
        return (l == 'l' ? 'w' : 'l');
    }
    else if (l == 'w')
    {
        return (r == 'w' ? 'l' : 'w');
    }
    else
    {
        return 'w';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, len;
    char c;
    string s;
    cin >> n >> q;

    char state = 'w';
    for (int i = n + 1; i >= 1; i--)
    {
        for (int j = 1 << (i - 1); j < (1 << i); j++)
        {
            tree[j] = state;
        }
        state = (state == 'w' ? 'l' : 'w');
    }

    for (int i = 0; i < q; i++)
    {
        cin >> c >> len >> s;
        int ti = 1;
        for (int j = 0; j < len; j++)
        {
            ti *= 2;
            if (s[j] == 'O')
            {
                ti += 1;
            }
        }
        if (c == 'A')
        {
            tree[ti] = 'f';
        }
        else
        {
            tree[ti] = getState(tree[2 * ti], tree[2 * ti + 1]);
        }
        while (ti > 1)
        {
            ti /= 2;
            if (tree[ti] == 'f')
            {
                continue;
            }
            char state = getState(tree[2 * ti], tree[2 * ti + 1]);
            if (tree[ti] == state)
            {
                break;
            }
            tree[ti] = state;
        }
        cout << (tree[1] == 'w' ? "Pressie" : "Kressie") << '\n';
    }
}