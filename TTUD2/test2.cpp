#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    string arr[1000];
    stack<char> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool isCorrect = true;
        for (char c : arr[i])
        {
            if (c == '(' || c == '{' || c == '[')
            {
                s.push(c);
            }
            else
            {
                if (s.empty() && (c == ')' || c == '}' || c == ']'))
                {
                    isCorrect = false;
                    break;
                }
                char top = s.top();
                s.pop();

                if (c == ')' && top != '(')
                {
                    isCorrect = false;
                    break;
                }
                else if (c == '}' && top != '{')
                {
                    isCorrect = false;
                    break;
                }
                else if (c == ']' && top != '[')
                {
                    isCorrect = false;
                    break;
                }
            }
        }
        if (!s.empty())
            isCorrect = false;

        if (isCorrect == true)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
   

    return 0;
}