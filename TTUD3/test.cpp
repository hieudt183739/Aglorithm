#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull n, m;
ull c[21][21];
ull i, j;
bool mark[21];
ull res[21];
ull cMin = 1e14;
ull best = 1e14;
ull sum = 0;

void KhoiTao()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = 1e14;
        }
    }
    for (int it = 1; it <= m; it++)
    {
        cin >> i >> j >> c[i][j];
        cMin = cMin < c[i][j] ? cMin : c[i][j];
    }
}

void Try(int k)
{
    if (sum + cMin * (n - k + 1) > best)
        return;
    for (int it = 1; it <= n; it++)
    {
        if (c[res[k - 1]][it] == 1e14)
            continue;

        else if (!mark[it])
        {
            mark[it] = true;
            sum = sum + c[res[k - 1]][it];
            res[k] = it;

            if (k == n)
            {
                best = best < sum + c[res[k]][1] ? best : sum + c[res[k]][1];
            }
            else
            {
                Try(k + 1);
            }

            mark[it] = false;
            sum = sum - c[res[k - 1]][it];
        }
    }
}

int main()
{
    cin >> n >> m;
    KhoiTao();
    res[1] = 1;
    mark[1] = true;
    Try(2);
    cout << best;

    return 0;
}