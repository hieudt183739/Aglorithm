#include <iostream>
using namespace std;
/*
  Cho hai số nguyên a và b. Yêu cầu viết chương trình tính tổng c=a+b bằng ngôn ngữ C/C++
*/
int main()
{
    unsigned long long a, b, c;
    unsigned long long a0, a1, b0, b1, c0, c1;
    c1 = 0;
    cin >> a >> b;

    a1 = a / 10;
    b1 = b / 10;
    a0 = a % 10;
    b0 = b % 10;

    c0 = a0 + b0;
    if (c0 > 10)
        c1 = 1;
    c0 = c0 % 10;
    c1 = a1 + b1 + c1;
    if (c1 > 0)
        cout << c1;
    cout << c0;

    return 0;
}