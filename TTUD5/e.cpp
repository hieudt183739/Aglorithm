#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(vector<int> x, int mid)
{
    int res = 0;
    int last = -mid - 1;
    for (const int &value : x)
    {
        if (value - last >= mid)
        {
            res++;
            last = value;
        }
    }
    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> x(n);
        for (int &value : x)
        {
            cin >> value;
        }
        sort(x.begin(), x.end());
        int low = 0;
        int hight = (int)1e9 + 10;
            while (low - hight < 1)
            {
                int mid = (low + hight) / 2;
                if (f(x, mid) < c)
                {
                    hight = mid;
                }
                else
                {
                    low = mid;
                }
            }
            cout << low << "\n";
        }

        return 0;
    }