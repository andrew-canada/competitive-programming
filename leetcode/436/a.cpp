#include <bits/stdc++.h>
using namespace std;

vector<int> assignElements(vector<int> &groups, vector<int> &elements)
{
    int n = groups.size();
    int m = elements.size();
    vector<int> assigned(n, -1);

    unordered_set<int> uniqueElements(elements.begin(), elements.end());

    unordered_map<int, int> elementIndex;
    for (int i = 0; i < m; ++i)
    {
        if (elementIndex.find(elements[i]) == elementIndex.end())
        {
            elementIndex[elements[i]] = i;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (const auto &elem : uniqueElements)
        {
            if (groups[i] % elem == 0)
            {
                assigned[i] = elementIndex[elem];
                break;
            }
        }
    }

    return assigned;
}
