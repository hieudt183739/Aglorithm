#include <iostream>
#include <cstring>
using namespace std;
const int Max = 1000;

int m, k;
int p[Max];
int kq[Max];

int check(long long x, bool output)
{
    int res = 1;
    long long cur = 0;
    if (output)
        memset(kq, 0, sizeof(kq));
    for (int i = m; i; i--)
    {
        if (p[i] > x)
            return 0;
        if (cur + p[i] <= x)
        {
            cur += p[i];
        }
        else
        {
            res++;
            if (output)
                kq[i] = 1;
            cur = p[i];
        }
    }
    if (output)
    {
        for (int i = 1; i <= m; i++)
        {
            if (res < k && kq[i] == 0)
            {
                kq[i] = 1;
                res++;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << p[i] << " ";
            if (kq[i])
                cout << " / ";
        }
        cout << endl;
    }
    return res <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> k;
        for (int i = 1; i <= m; i++)
        {
            cin >> p[i];
        }

        long long low = 0, high = 1e10;
        while (high - low > 1)
        {
            long long mid = (high + low) >> 1;
            if (check(mid, 0))
                high = mid;
            else
                low = mid;
        }

        check(high, 1);

    }

    return 0;
}