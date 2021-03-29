#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;

int f(vector<int> &x, int mid)
{
    int count = 0;
    count++;
    int pre_x = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] - pre_x >= mid)
        {
            count++;
            pre_x = x[i];
        }
    }
    return count;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> c;
        vector<int> x(n);

        for (int &value : x)
        {
            cin >> value;
        }

        sort(x.begin(), x.end());

        int high = x.back();
        int low = 0;

        while (high - low > 1)
        {
            int mid = (low + high) / 2;
            if (f(x, mid) < c)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        cout << low << '\n';
    }

    return 0;
}
