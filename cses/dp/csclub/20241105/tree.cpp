#include <bits/stdc++.h>

using namespace std;

int tree[17];

/*
given parent i,
- left child is 2i
- right child is 2i + 1
*/

int main()
{
    tree[1] = 2;

    // parent is 1
    tree[2] = 7; // 2*1
    tree[3] = 5; // 2*1 + 1

    // parent is 2
    tree[4] = 2; // 2*2
    tree[5] = 6; // 2*2 + 1
    tree[6] = 9;
    tree[10] = 5;
    tree[11] = 11;
    tree[12] = 4;
}