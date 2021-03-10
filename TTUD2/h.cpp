#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        string s;
        cin >> s;
        stack<char> st;

        bool khong_phu_hop = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                {
                    khong_phu_hop = true;
                    break;
                }
                char u = st.top();
                st.pop();
                if (s[i] == ')' && u != '(')
                {
                    khong_phu_hop = true;
                    break;
                }
                if (s[i] == ']' && u != '[')
                {
                    khong_phu_hop = true;
                    break;
                }
                if (s[i] == '}' && u != '{')
                {
                    khong_phu_hop = true;
                    break;
                }
            }
        }
        if (khong_phu_hop = true)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }
}