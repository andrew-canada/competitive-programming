#include <stdio.h>
#include <string>

int start;
std::string s;

int main()
{
    scanf("%d", &start);
    while (true)
    {
        start++;
        s = std::to_string(start);
        bool distinct = true;
        for (int i = 0; i < s.length() - 1; i++)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    distinct = false;
                    break;
                }
            }
            if (!distinct)
            {
                break;
            }
        }
        if (distinct)
        {
            printf("%d", start);
            return 0;
        }
    }
}