#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    int *iArr = new int[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> iArr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int max_j = i;
        for (int j = i + 1; j < n; j++)
        {
            if (i < j && iArr[i] > iArr[j] && max_j < j)
                max_j = j;
        }
        cout << max_j - i - 1 << " ";
    }

    return 0;
}