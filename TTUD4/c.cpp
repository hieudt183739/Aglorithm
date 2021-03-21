

/*
At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the number of courses assigned to her/him. How to assign n courses to m teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.

Input
The input consists of following lines

Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
Line m+2: contains an integer k
Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
Output
The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
*/

#include <iostream>
using namespace std;

int m, n;
bool canTeach[50][50];// canTeach[i][j]=true: giao vien i co the nhan mon j
bool conflict[50][50];
int teach[50];// mon i duoc giao vien teach[i] nhan
int load[50];// load[i] la so lop gia viet "i" da nhan
int res = 1e8;

void KhoiTao()
{

    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int k;
            cin >> k;
            canTeach[i][k] = true;
        }
    }

    int c;
    cin >> c;
    for (int it = 1; it <= c; it++)
    {
        int i, j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }

    for (int it = 0; it < 50; it++)
    {
        teach[it] = 0;
    }
}

bool noConflict(int it, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (teach[i] == it && conflict[i][k])
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
            // load[it]+1 <res: nhanh can
            if (load[it] + 1 < res && canTeach[it][k] && noConflict(it, k))
            {
                load[it]++;
                teach[k] = it;
                Try(k + 1);
                load[it]--;
                teach[k] = 0;
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    KhoiTao();
    Try(1);
    cout << res;

    return 0;
}