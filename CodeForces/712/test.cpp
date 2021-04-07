#include <iostream>
#define Max 200005
using namespace std;

char s[Max];
int n;
int t0, t1;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s[1];
        t0 = 0, t1 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '1')
                t1++;
            else
                t0++;
        }

        if (t0 & 1 || s[1] == '0' || s[n] == '0')
        {
            cout << "NO"
                 << "\n";
            return 0;
        }
        else
        {
            cout << "YES"
                 << "\n";
            int count = 0;
            for (int i = 1; i <= n; i++)
            {
                if (s[i] == '1' && i <= t1 / 2)
                {
                    cout << '(';
                }
                else if (s[i] == '1' && i > t1 / 2)
                {
                    cout << ')';
                }
                else
                {
                    count++;
                    if (count & 1)
                        cout << '(';
                    else
                        cout << ')';
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
