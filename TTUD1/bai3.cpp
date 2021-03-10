#include <iostream>
using namespace std;
/*
In ra (a+b) mod (10^9+7) 
*/
int main()
{
    unsigned long long a, b;
    unsigned long long a1 = 0, b1 = 0, a2 = 0, b2 = 0, c1 = 0, c2 = 0;
    int iSoChia = 1000000000 + 7;
    cin >> a >> b;

    a1 = a / 2;
    b1 = b / 2;
    c1 = a1 + b1;

    c2 = a - a1;
    c2 += b - b1;

    int mod1 = c1 % iSoChia;
    int mod2 = c2 % iSoChia;

    int mod = mod1 + mod2;

    if (mod >= iSoChia)
        mod = mod % iSoChia;
    cout << mod;

    return 0;
}