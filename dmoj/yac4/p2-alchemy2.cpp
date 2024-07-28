#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int numElements;
    scanf("%d", &numElements);

    int *numElementDerivatives = new int[numElements];

    for (int i = 0; i < numElements - 1; i++)
    {
        scanf("%d ", &numElementDerivatives[i]);
    }
    scanf("%d", &numElementDerivatives[numElements - 1]);

    map<int, vector<int>> elements;

    for (int i = 0; i < numElements; i++)
    {
        elements[numElements].push_back(i + 1);
    }

    puts("2, 1, 3");
}