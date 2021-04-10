#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = (int)1e9 + 7;

int n, K, Q;
int d[50];
int mark[50];
int capacity[50];
int vanChuyen[50];
int fac[50];
int res = 0;

void Try(int m)
{
    for (int i = 1; i <= K; i++)
    {
        if (d[m] <= capacity[i] && (i == 1 || vanChuyen[i-1] > 0))
        {
            capacity[i] -= d[m];
            vanChuyen[i]++;

            if (m == n)
            {
                
                int tmp = 1;
                for (int i = 1; i <= K; i++)
                {
                    tmp = tmp * fac[vanChuyen[i]] % MOD;
                    cout<<tmp<<"\n";
                    cout<<i<<" "<<vanChuyen[i]<<"\n\n";
                }
                res += (res + tmp) % MOD;
                cout<<"-------------\n";
            }
            else
            {
                Try(m + 1);
            }

            capacity[i] += d[m];
            vanChuyen[i]--;
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= K; i++)
    {
        capacity[i] = Q;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    cout<<"\n";

    fac[0]=1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }

    Try(1);

    cout << res << "\n";

    return 0;
}