#include <iostream>
using namespace std;
#define ll long long
int const Max = 1e6 + 1;

int n;
ll a[Max];
ll SumEven[Max];
ll SumOdd[Max];
ll res = -1e6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (!(a[1] & 1))
        SumEven[1] = a[1];
    else
        SumOdd[1] = a[1];

    for (int i = 2; i <= n; i++)
    {
        if (!(a[i] & 1))
        {
            SumEven[i] = max(SumEven[i - 1] + a[i], a[i]);
            if (SumOdd[i - 1] != 0)
                SumOdd[i] = SumOdd[i - 1] + a[i];
            res = max(SumEven[i], res);
        }
        else
        {
            if (SumOdd[i - 1] != 0)
                SumEven[i] = SumOdd[i - 1] + a[i];
            else
                SumEven[i] = 0;
            SumOdd[i] = max(SumEven[i-1] + a[i], a[i]);
            res = max(SumEven[i], res);
        }
    }
    
    cout << res << "\n";
    return 0;
}