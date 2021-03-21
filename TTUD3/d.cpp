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
bool mark_passenger[12]; // danh dau hanh khach i co o tren xe bus ko
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
    if (best <= sum + cMin * (2 * n - t + 1))
    {
        return;
    }
    else
    {
        for (int it = 1; it <= 2 * n; it++)
        {
            if (dem == 0 && it <= n)
            {
                if (!mark[it])
                {
                    mark[it] = true;
                    mark_passenger[it] = true;
                    res[t] = it;
                    sum = sum + c[res[t - 1]][it];

                    int pre_dem = dem;
                    dem++;

                    Try(t + 1);
                    mark[it] = false;
                    mark_passenger[it] = false;
                    sum = sum - c[res[t - 1]][it];
                    dem = pre_dem;
                }
            }
            else if (dem == k && it >= n + 1)
            {
                if (!mark[it] && mark_passenger[it - n])
                {
                    mark[it] = true;
                    mark_passenger[it - n] = false;
                    res[t] = it;
                    sum = sum + c[res[t - 1]][it];

                    int pre_dem = dem;
                    dem--;

                    Try(t + 1);
                    mark[it] = false;
                    mark_passenger[it - n] = true;
                    sum = sum - c[res[t - 1]][it];
                    dem = pre_dem;
                }
            }
            else if (dem >= 1 && dem < k)
            {
                if (it <= n && !mark[it])
                {
                    mark[it] = true;
                    mark_passenger[it] = true;
                    res[t] = it;
                    sum = sum + c[res[t - 1]][it];

                    int pre_dem = dem;
                    dem++;

                    Try(t + 1);
                    mark[it] = false;
                    mark_passenger[it] = false;
                    sum = sum - c[res[t - 1]][it];
                    dem = pre_dem;
                }
                else if (it >= n + 1 && !mark[it] && mark_passenger[it - n])
                {
                    mark[it] = true;
                    mark_passenger[it - n] = false;
                    sum = sum + c[res[t - 1]][it];

                    int pre_dem = dem;
                    dem--;

                    if (t == 2 * n)
                    {
                        best = best < sum + c[res[t]][0] ? best : sum + c[res[t]][0];
                    }
                    else
                        Try(t + 1);
                    mark[it] = false;
                    mark_passenger[it - n] = true;
                    sum = sum - c[res[t - 1]][it];
                    dem = pre_dem;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    khoiTao();
    res[0] = 0;
    Try(1);
    cout << best;
    return 0;
}