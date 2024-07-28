#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

vector<int> cell(mxN + 1);
vector<int> newCell(mxN + 1);

int main()
{
    int n, g;
    cin >> n >> g;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        cell[i] = s[i] - '0';
    }
    while (g--)
    {
        newCell.clear();
        newCell[0] = cell[n - 1] ^ cell[1];
        newCell[n - 1] = cell[n - 2] ^ cell[0];
        for (int i = 1; i < n - 1; i++)
        {
            newCell[i] = cell[i - 1] ^ cell[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            cell[i] = newCell[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << cell[i];
    }
}