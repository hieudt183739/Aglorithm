#include <iostream>
using namespace std;
int const Max = 1e6 + 1;

int a[Max];
long long sum[Max];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sum[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    

    return 0;
}