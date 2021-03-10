#include <iostream>
#include <vector>

using namespace std;

void stdio_doing(int n)
{
    n = n + 1;
    cout << n;
}

void stdio(int n)
{
    cout << n << " ";
}

void for_each(vector<int> v1, void (*func)(int a))
{
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        func(*i);
    }
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for_each(v, stdio);

    return 0;
}