#include <iostream>
#include <algorithm>
using namespace std;

int iArr[11];
bool mark[11];
int n;

void print_sol(int arr[]);
void Try(int k);

int main()
{
    cin >> n;
    Try(1);
    return 0;
}

void print_sol(int iArr[])
{
    for (int i = 1; i <= n; i++)
    {
        cout << iArr[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!mark[i])
        {
            mark[i] = true;
            iArr[k] = i;
            if (k == n)
            {
                print_sol(iArr);
            }
            else
            {
                Try(k + 1);
            }
            mark[i] = false;
        }
    }
}