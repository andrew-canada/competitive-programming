#include <bits/stdc++.h>

using namespace std;

string addStrings(const string &num1, const string &num2)
{
    int carry = 0;
    string result;
    int i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string multiplyStrings(const string &num1, const string &num2)
{
    int m = num1.size(), n = num2.size();
    vector<int> result(m + n, 0);
    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string resultStr;
    for (int num : result)
    {
        if (!(resultStr.empty() && num == 0))
        {
            resultStr.push_back(num + '0');
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}

string squareString(const string &num)
{
    if (num.size() <= 9)
    {
        long long n = stoll(num);
        return to_string(n * n);
    }
    int mid = num.size() / 2;
    string A = num.substr(0, mid);
    string B = num.substr(mid);
    string A2 = squareString(A);
    string B2 = squareString(B);
    string AB = multiplyStrings(A, B);
    string AB2 = addStrings(AB, AB);
    string A2_shifted = A2 + string(2 * (num.size() - mid), '0');
    string AB2_shifted = AB2 + string(num.size() - mid, '0');
    return addStrings(addStrings(A2_shifted, AB2_shifted), B2);
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << squareString(s) << endl;
    return 0;
}