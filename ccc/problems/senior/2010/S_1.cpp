#include <bits/stdc++.h>

using namespace std;

struct comp
{
    int val;
    string name;
    bool operator<(const comp &c)
    {
        return val == c.val ? name < c.name : val > c.val;
    }
};

int main()
{
    int n;
    cin >> n;
    string name;
    int r, s, d;
    vector<comp> computer;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> r >> s >> d;
        computer.push_back({2 * r + 3 * s + d, name});
    }
    sort(computer.begin(), computer.end());
    if (computer.size() == 1)
    {
        cout << computer[0].name << '\n';
    }
    else if (computer.size() > 1)
    {
        cout << computer[0].name << '\n'
             << computer[1].name << '\n';
    }
}