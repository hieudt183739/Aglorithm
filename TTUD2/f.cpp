#include <iostream>
using namespace std;

int main()
{
    int n, b = 0;
    cin >> n >> b;
    int *a = new int[200000];
    int *max_prefix = new int[200000];
    int *max_suffix = new int[200000];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    max_prefix[0] = a[0];
    max_suffix[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
        max_prefix[i] = max(max_prefix[i - 1], a[i]);
    for (int i = n - 2; i >= 0; i--)
        max_suffix[i] = max(max_suffix[i + 1], a[i]);
    int res = -1;
    for (int i = 1; i < n - 1; i++)
        if (max_prefix[i - 1] - a[i] >= b && max_suffix[i + 1] - a[i] >= b)
            res = max_prefix[i - 1] - a[i] + max_suffix[i + 1] - a[i];

    cout << res;

    delete[] a;
    delete[] max_prefix;
    delete[] max_suffix;
    return 0;
}