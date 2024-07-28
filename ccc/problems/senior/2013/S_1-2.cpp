#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    while (true)
    {
        ++n;
        s = to_string(n);
        bool found = true;
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    found = false;
                    break;
                }
            }
            if (!found)
            {
                break;
            }
        }
        if (found)
        {
            cout << n;
            return 0;
        }
    }
}