#include <iostream>
using namespace std;

int n, k, cMin = 1e9;
int c[30][30];
bool visited[30];
int x[30];
int passengerOnBus = 0;
int best = 1e9;
int cur_sum = 0;

void Try(int t)
{
    int it = 1;
    if (passengerOnBus == k)
        it = n + 1;
    for (; it <= 2 * n; it++)
    {

        if (!visited[it])
        {
            visited[it] = true;
            cur_sum += c[x[t - 1]][it];
            x[t] = it;
            int pre = passengerOnBus;
            if (it >= n + 1)
                passengerOnBus--;
            else
                passengerOnBus++;

            if (t == n)
            {
                best = min(best, cur_sum + c[x[t]][0]);
                continue;
            }
            Try(t + 1);

            visited[it] = false;
            cur_sum -= c[x[t - 1]][it];
            x[t] = 0;
            passengerOnBus = pre;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cMin = min(cMin, c[i][j]);
        }
    visited[0] = true;
    x[0] = 0;
    Try(1);
    cout << best << "\n";

    return 0;
}