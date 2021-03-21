/*
The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced . There are N courses 1,2,…,N that must be assigned to M periods 1,2,…,M. Each courses i has credit ci and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period. The prerequisites information is represented by a matrix AN×N in which Ai,j = 1 indicates that courses i must be assigned to a period before the period to which the course j is assigned. Compute the assignment such that the maximum load for all periods is minimal.

Input
Line 1 contains N and M (2≤N≤16,2≤M≤5)
Line 2 contains c1,c2,…,cN
Line i+2(i=1,…,N) contains the ith line of the matrix A
Output
Unique line contains that maximum load for all periods of the solution found
*/

#include <iostream>
using namespace std;

int n, m;
int c[50];
int A[50][50];
int load[50];// load[i]: so tin chi ki i da hoc
int teach[50];// teach[i]: mon i hoc o ki teach[i]
int res = 1e8;

void KhoiTao()
{
    cin >> n >> m;
    for (int it = 1; it <= n; it++)
    {
        cin >> c[it];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int it = 0; it < 50; it++)
    {
        teach[it] = 1e8;
        load[it] = 0;
    }
}



bool noConflict(int k, int it)
{
    for (int i = 1; i <= n; i++)
    {
        if (A[k][i] == 1 &&  teach[i] <= it)// mon i phai hoc sau mon k
        {
            return false;
        }
    }
    return true;
}

void Try(int k)
{
    if (k > n)
    {
        int maxLoad = 0;
        for (int it = 1; it <= m; it++)
        {
            maxLoad = max(maxLoad, load[it]);
        }
        res = min(res, maxLoad);
        return;
    }
    else
    {
        for (int it = 1; it <= m; it++)
        {
            if (load[it] + c[k] < res && noConflict(k, it))
            {
                load[it] += c[k];
                teach[k] = it;
                Try(k + 1);
                load[it] -= c[k];
                teach[k] = 1e8;
            }
        }
    }
}

int main()
{
    KhoiTao();
    Try(1);
    cout << res;
    return 0;
}
