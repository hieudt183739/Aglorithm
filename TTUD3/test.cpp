#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull n, k;
ull c[23][23];
ull cMin = 1e14;
ull best = 1e14;
ull dem = 0;
ull sum = 0;
bool mark[23];
bool mark_passenger_onBus[12]; // danh dau hanh khach i co o tren xe bus ko
ull res[23];

void khoiTao()
{
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cMin = cMin < c[i][j] ? cMin : c[i][j];
        }
    }
}

void Try(int t)
{
    if (sum + 2 * (n - t + 1) > best)
        return;
    else
    {

    }
}