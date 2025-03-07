#include <bits/stdc++.h>
using namespace std;

// 500000 is less than 2^19
int stree[1 << 20];

int left_child(int idx)
{
    return 2 * idx + 1;
}

int right_child(int idx)
{
    return 2 * idx + 2;
}

// Add gi to all members of the tree from 0 to xi, inclusive.
void update_tree(int sz, int gi, int xi)
{
    int tree_idx = 0;
    if (xi == sz)
    { // applies to all values
        stree[tree_idx] += gi;
        return;
    }
    for (int chunk = sz / 2; chunk > 0; chunk /= 2)
    {
        if (xi >= chunk)
        {
            xi -= chunk;
            stree[left_child(tree_idx)] += gi;
            tree_idx = right_child(tree_idx);
        }
        else
        {
            tree_idx = left_child(tree_idx);
        }
    }
}

// Find the net amount of growth received by index x.
int query_tree(int sz, int xi)
{
    int answer = 0;
    int tree_idx = 0;
    for (int chunk = sz / 2; chunk > 0; chunk /= 2)
    {
        answer += stree[tree_idx];
        if (xi > chunk)
        {
            xi -= chunk;
            tree_idx = right_child(tree_idx);
        }
        else
        {
            tree_idx = left_child(tree_idx);
        }
    }
    answer += stree[tree_idx];
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    int sz = 1;
    while (sz < n)
    {
        sz <<= 1;
    }
    for (int i = 0; i < (2 * sz - 1); ++i)
    {
        stree[i] = 0;
    }
    int si, ei, gi, ci;
    for (int i = 0; i < b; ++i)
    {
        cin >> si >> ei >> gi >> ci;
        // first add gi to everything up to and including ei
        update_tree(sz, gi, ei);
        // then subtract gi from everything up to and including si-1
        if (si > 1)
        {
            update_tree(sz, -gi, si - 1);
        }
        // then query the indicated location
        cout << query_tree(sz, ci) << '\n';
    }
}