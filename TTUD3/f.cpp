#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull n;
ull c[25][25];
ull i, j;
bool mark_passenger[11];
ull res_dich[11];
ull res_passenger[11];
ull cMin = 1e14;
ull best = 1e14;
ull sum = 0;

void KhoiTao()
{
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> c[i][j];
            cMin = cMin < c[i][j] ? cMin : c[i][j];
        }
    }
}

void Try(int k)
{
    if (sum + 2 * cMin * (n - k + 1) > best)
        return;
    for (int it = 1; it <= n; it++)
    {
        if (!mark_passenger[it])
        {
            ull chi_phi = c[res_dich[k - 1]][it] + c[it][it + n];

            mark_passenger[it] = true;

            sum = sum + chi_phi;
            res_passenger[k] = it;
            res_dich[k] = it + n;

            if (k == n)
            {
                best = best < sum + c[res_dich[k]][0] ? best : sum + c[res_dich[k]][0];
            }
            else
            {
                Try(k + 1);
            }

            mark_passenger[it] = false;
            sum = sum - chi_phi;
        }
    }
}

int main()
{
    cin >> n;
    KhoiTao();
    res_passenger[0] = 0;
    res_dich[0] = 0;
    Try(1);
    cout << best;

    return 0;
}
