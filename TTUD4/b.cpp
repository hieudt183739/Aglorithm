/*
Một nhà thám hiểm cần đem theo một cái túi có trọng lượng không quá b. Có n đồ vật có thể đem theo. Đồ vật thứ j có trọng lượng aj và giá trị sử dụng cj. Hỏi nhà thám hiểm cần đem theo những đồ vật nào để cho tổng giá trị sử dụng là lớn nhất mà tổng trọng lượng đồ vật mang theo cái túi không vượt quá b?

Input
Dòng đầu tiên chứa hai số nguyên dương n,b (n≤30,b≤106).

Dòng thứ j trong số n dòng tiếp theo mỗi dòng ghi ra hai số nguyên dương aj,cj≤106.

Output
Ghi ra duy nhất một số là tổng giá trị lớn nhất tìm được của các đồ vật cho vào túi.

Example
inputCopy
2 6
4 2
3 2
outputCopy
2
*/

#include <iostream>
using namespace std;

const int N = 33;
int n, b;
int a[N], c[N];
int kq = 0;

void duyet(int u, int sumA, int sumB)
{
    if (sumA > b)
        return;
    if (u == n + 1)
    {
        if (sumA <= b)
            kq = max(kq, sumB);
        return;
    }
    duyet(u + 1, sumA, sumB);
    duyet(u + 1, sumA + a[u], sumB + c[u]);
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    duyet(1, 0, 0);
    cout << kq << endl;

    return 0;
}