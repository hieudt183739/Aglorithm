/*
There are n passengers_ 1,2,…,n. The passenger i want to travel from point i to point i+n(i=1,2,…,n). 
There is a taxi located at point 0 for transporting the passengers. 
Given the distance matrix c(2n+1)∗(2n+1) in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n)
Compute the shortest route for the taxi, serving n passengers and coming back to point 0 
such that at any moment, there are no more than one passenger in the taxi, and no point is visited more than once (except for point 0, which can be visited up to twice)

Input
Line 1 contains n(1≤n≤11). Line i+1(i=1,2,…,2n+1) contains the ith line of the matrix c.

Output
Unique line contains the length of the shortest route.
*/


#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull n;
ull c[23][23];
ull i, j;
bool mark_passenger[12];
ull res_dich[12];// chi can luu cac dich da tham
ull cMin = 1e14;
ull best = 1e14;
ull sum = 0;

void KhoiTao()
{
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> c[i][j];
            cMin = cMin < c[i][j] ? cMin : c[i][j];
        }
    }
}

void Try(int k)
{
    if (sum + 2 * cMin * (n - k + 1) > best)
        return;
    for (int it = 1; it <= n; it++)
    {
        if (!mark_passenger[it])
        {
            ull chi_phi = c[res_dich[k - 1]][it] + c[it][it + n];

            mark_passenger[it] = true;
            sum = sum + chi_phi;
            res_dich[k] = it + n;

            if (k == n)
            {
                best = best < sum + c[res_dich[k]][0] ? best : sum + c[res_dich[k]][0];
            }
            else
            {
                Try(k + 1);
            }

            mark_passenger[it] = false;
            sum = sum - chi_phi;
        }
    }
}

int main()
{
    cin >> n;
    KhoiTao();
    res_dich[0] = 0;
    Try(1);
    cout << best;

    return 0;
}
