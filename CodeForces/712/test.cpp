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
        cin >> s + 1;

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
        }
        else
        {
            cout << "YES"
                 << "\n";

            for (int i = 1, n0 = 0, n1 = 0; i <= n; i++)
            {
                if (s[i] == '1')
                    putchar((++n1 <= t1 / 2) ? '(' : ')');
                else
                {
                    if (++n0 & 1)
                        cout << '(';
                    else
                        cout << ')';
                }
            }
            cout << "\n";

            for (int i = 1, n0 = 0, n1 = 0; i <= n; i++)
            {
                if (s[i] == '1')
                    putchar((++n1 <= t1 / 2) ? '(' : ')');
                else
                {
                    if (++n0 & 1)
                        cout << ')';
                    else
                        cout << '(';
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
