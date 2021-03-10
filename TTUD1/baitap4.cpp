#include <iostream>
using namespace std;
/*
Input
One line contains two integers a and b (1≤a,b≤18446744073709551614)

Output
The value ab mod (109+7)

Sử dụng:
Định lý Euler: https://en.wikipedia.org/wiki/Euler%27s_theorem
Hàm phi Euler: https://en.wikipedia.org/wiki/Euler%27s_totient_function
*/

unsigned long long power(unsigned long long a, unsigned long long b, int iSoChia);

int main()
{
    unsigned long long a, b, du = 0;
    int iSoChia = 1000000000 + 7;

    cin >> a >> b;

    b = b % iSoChia; // định lý Euler
    du = power(a, b, iSoChia);
    cout << du;

    return 0;
}

unsigned long long power(unsigned long long a, unsigned long long b, int iSoChia)
{
    unsigned long long res = 1;
    a = a % iSoChia;
    while (b > 0)
    {
        if (b & 1) // bitwise: b là lẻ thì...
        {
            res = (res * a) % iSoChia;
        }

        b = b >> 1; //  b/2
        a = (a * a) % iSoChia;
    }
    return res;
}