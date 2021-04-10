#include <iostream>
using namespace std;
#define ull unsigned long long

ull const MOD = (ull)1e9 + 7;

ull n, k, q;
ull d[50];
ull capacity[50];
ull vanChuyen[50];
ull res = 0;
ull Fac[50];

// void Try(ull m)
// {
//     for (ull i = 1; i <= k; i++)
//     {
//         if (vanChuyen[i - 1] == 0 && i > 1)
//             return;
//         if (d[m] <= capacity[i])
//         {
//             capacity[i] -= d[m];
//             vanChuyen[i]++;

//             if (m == n)
//             {
//                 ull tmp = 1;
//                 for (ull i = 1; i <= k; i++)
//                 {
//                     // cout << i << vanChuyen[i] << "\n";
//                     tmp = tmp * Fac[vanChuyen[i]] % MOD;
//                 }
//                 res = (res + tmp) % MOD;
//                 // cout<<res<<"\n\n";
//             }
//             else
//                 Try(m + 1);

//             capacity[i] += d[m];
//             vanChuyen[i]--;
//         }
//     }
// }

void Try(int m)
{
    if (m > n)
    {
        int so_cach = 1;
        for (int i = 1; i <= k; i++)
        {
            so_cach = 1ll * so_cach * Fac[vanChuyen[i]] % MOD;
            if (vanChuyen[i] == 0)
                so_cach = 0;
            if (capacity[i] < 0)
                so_cach = 0;
        }
        res = (res + so_cach) % MOD;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (i == 0 || vanChuyen[i - 1] > 0)
        {
            vanChuyen[i]++;
            capacity[i] -= d[i];
            Try(m + 1);
            vanChuyen[i]--;
            capacity[i] += d[i];
        }
    }
}

int main()
{
    cin >> n >> k >> q;
    for (ull i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (ull i = 1; i <= k; i++)
    {
        capacity[i] = q;
    }
    for (ull i = 1; i <= k; i++)
    {
        vanChuyen[i] = 0;
    }

    // tinh giai thua
    Fac[0] = 1;
    for (ull i = 1; i <= q; i++)
    {
        Fac[i] = Fac[i - 1] * i % MOD;
    }

    Try(1);

    cout << res << "\n";
    return 0;
}