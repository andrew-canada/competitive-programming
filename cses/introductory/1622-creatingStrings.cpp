#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    vector<string> vec;
    sort(s.begin(), s.end());
    do
    {
        vec.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << vec.size() << '\n';
    for (string s : vec)
    {
        cout << s << "\n";
    }
}