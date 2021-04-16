#include <iostream>
using namespace std;

const int Max = 1e6 + 1;
int a[101];
bool c[101][101];
int best = 1e9;

int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        c[u][v] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == true)
            {
                for (int k = 1; k <= m; k++)
                {
                    if (c[j][k] == true && c[k][i] == true)
                        best = min(best, a[i] + a[j] + a[k]);
                }
            }
        }
    }
    if (best == 1e9)
        best = -1;
    cout << best;

    return 0;
}