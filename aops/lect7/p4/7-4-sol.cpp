#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25;
const char LOSING = 0;
const char WINNING = 1;
const char FORBIDDEN = 2;

char stree[1 << (MAX_N + 1)];

// Node 0 is the root, node 1 holds string 'M', node 2 holds string 'O',
//   node 3 holds string 'MM', etc.
int get_node(string s, int l)
{
    int answer = 0;
    for (int i = 0; i < l; ++i)
    {
        answer *= 2;
        if (s[i] == 'O')
        {
            answer += 1;
        }
    }
    answer += (1 << l);
    answer -= 1;
    return answer;
}

int eval_node(int left_child, int right_child)
{
    if ((left_child == FORBIDDEN) && (right_child == FORBIDDEN))
    {
        return LOSING; // can't move from here
    }
    else if (left_child == FORBIDDEN)
    {
        return ((right_child == LOSING) ? WINNING : LOSING);
    }
    else if (right_child == FORBIDDEN)
    {
        return ((left_child == LOSING) ? WINNING : LOSING);
    }
    else if (left_child == WINNING)
    {
        return ((right_child == WINNING) ? LOSING : WINNING);
    }
    else
    { // left_child == LOSING and active player can move there
        return WINNING;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int sz = 1 << (n + 1);
    // To start out, any node in the bottom layer is a win, any node above that
    //   is a loss, etc.
    int val = WINNING;
    for (int lv = n + 1; lv >= 1; --lv)
    {
        int last = (1 << lv) - 2;
        int first = (1 << (lv - 1)) - 1;
        for (int i = first; i <= last; ++i)
        {
            stree[i] = val;
        }
        val = (val == WINNING ? LOSING : WINNING);
    }
    char ti;
    int li;
    string si;
    int lowest_level_start = (1 << n) - 1;
    // Process each query.
    for (int i = 0; i < q; ++i)
    {
        cin >> ti >> li >> si;
        int node = get_node(si, li);
        if (ti == 'A')
        {
            stree[node] = FORBIDDEN;
        }
        else
        { // ti == 'D', unforbid
            if (node >= lowest_level_start)
            {
                stree[node] = WINNING;
            }
            else
            {
                stree[node] = eval_node(stree[(2 * node) + 1], stree[(2 * node) + 2]);
            }
        }
        // Update ancestors as needed.
        while (node > 0)
        { // don't try to go beyond the root
            node = (node - 1) / 2;
            if (stree[node] == FORBIDDEN)
            {
                continue; // no need to update beyond this point
            }
            int new_eval = eval_node(stree[(2 * node) + 1], stree[(2 * node) + 2]);
            if (stree[node] == new_eval)
            {
                break; // no change, so no other ancestor will change either
            }
            stree[node] = new_eval;
        }
        cout << (stree[0] == WINNING ? "Pressie" : "Kressie") << '\n';
    }
}