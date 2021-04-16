#include <iostream>
#include <algorithm>
using namespace std;
const int Max = 100000;

int n, q;
int x[Max], m[Max];

int binarySearchCount(int arr[], int n, int key)
{
    int left = 1, right = n;

    int mid;
    while (left < right)
    {
        mid = (right + left) >> 1;

        if (arr[mid] == key)
        {

            while (mid + 1 < n && arr[mid + 1] == key)
                mid++;
            break;
        }

        else if (arr[mid] > key)
            right = mid;

        else
            left = mid + 1;
    }

    while (mid > -1 && arr[mid] > key)
        mid--;

    return mid + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    x[0] = 0;
    sort(x, x + n + 1);

    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> m[i];
    }

    for (int i = 1; i <= q; i++)
    {

        cout << binarySearchCount(x, n + 1, m[i])-1 << "\n";
    }

    return 0;
}