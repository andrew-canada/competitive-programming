#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

string add(const string &s1, const string &s2)
{
    string ans;
    int carry = 0, sum = 0, i1 = s1.size() - 1, i2 = s2.size() - 1;
    while (carry || i1 >= 0 || i2 >= 0)
    {
        sum = carry;
        if (i1 >= 0)
        {
            sum += s1[i1--] - '0';
        }
        if (i2 >= 0)
        {
            sum += s2[i2--] - '0';
        }
        ans.pb(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string mult(const string &s1, const string &s2)
{
    vector<int> res(s1.size() + s2.size(), 0);
    string ans;
    int prod, sum;
    for (int i1 = s1.size() - 1; i1 >= 0; i1--)
    {
        for (int i2 = s2.size() - 1; i2 >= 0; i2--)
        {
            prod = (s1[i1] - '0') * (s2[i2] - '0');
            sum = prod + res[i1 + i2 + 1];
            res[i1 + i2 + 1] = sum % 10, res[i1 + i2] += sum / 10;
        }
    }
    for (int i : res)
    {
        ans.pb(i + '0');
    }
    return ans;
}

string square(const string &s)
{
    if (s.size() <= 9)
    {
        ll n = stoll(s);
        return to_string(n * n);
    }
    int mid = s.size() / 2;
    string a = s.substr(0, mid), b = s.substr(mid);
    string aa = square(a), bb = square(b);
    string ab = mult(a, b);
    string ab2 = add(ab, ab);
    string aas = aa + string(2 * (s.size() - mid), '0'), ab2s = ab2 + string(s.size() - mid, '0');
    return add(add(aas, ab2s), bb);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    cout << square(s);
}