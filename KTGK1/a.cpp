#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 0;
    int x = 0;
    char d[10];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        fflush(stdin);
        cin >> d;
        if (d[0] == '-' || d[2] == '-')
        {
            x--;
        }
        else
            x++;
    }
    cout << x;

    return 0;
}