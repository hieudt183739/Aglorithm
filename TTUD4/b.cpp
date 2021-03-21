#include <iostream>
using namespace std;

const int N = 33;
int n, b;
int a[N], c[N];
int kq = 0;

void duyet(int u, int sumA, int sumB)
{
    if (sumA > b)
        return;
    if (u == n + 1)
    {
        if (sumA <= b)
            kq = max(kq, sumB);
        return;
    }
    duyet(u + 1, sumA, sumB);
    duyet(u + 1, sumA + a[u], sumB + c[u]);
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    duyet(1, 0, 0);
    cout << kq << endl;

    return 0;
}