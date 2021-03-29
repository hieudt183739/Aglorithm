#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip> 
#define PI 3.14159265358979323846
using namespace std;

int  enough(vector<float> v, float mid)
{
    int sum = 0;
    for (float &value : v)
    {
        sum += value / mid;
    }
    return sum;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        float n, f;
        cin >> n >> f;
        f++;
        vector<float> v(n);
        for (float &value : v)
        {
            int r;
            cin >> r;
            value = PI * r * r;
        }
        float low = 0;
        float hight = v.back();

       int dem=100;
        while (dem--)
        {
            float mid = (low + hight) / 2;
            if (enough(v, mid) < f)
            {
                hight = mid ;
            }
            else
            {
                low = mid;
            }
        }
        cout <<fixed<<setprecision(10) << low << "\n";
    }

    return 0;
}