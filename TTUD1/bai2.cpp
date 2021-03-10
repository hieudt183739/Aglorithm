#include <iostream>
using namespace std;
#define MAX 1000000

/*
Cho mảng s=(a1,...,an)

Một đoạn s(i,j)=(ai,...,aj),1≤i≤j≤n

Trọng số w(i,j)=ai+ai+1...+aj

Hãy tìm một đoạn trong mảng có trọng số lớn nhất, nghĩa là tổng các số trong đoạn là lớn nhất
*/

//c3: Quy hoạch động

int main()
{
    int *iArr = new int[1000000];
    int *s = new int[1000000];
    int n, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> iArr[i];
    }

    max = iArr[0];
    s[0] = iArr[0];

    for (int i = 1; i < n; i++)
    {
        s[i] = (s[i - 1] + iArr[i]) > iArr[i] ? (s[i - 1] + iArr[i]) : iArr[i];
        max = max > s[i] ? max : s[i];
    }
    cout << max;
    delete[] iArr;
    return 0;
}

// c2: chia để trị
// int findMaxSeq(int iArr[], int l, int r);
// int findMaxL(int iArr[], int l, int r);
// int findMaxR(int iArr[], int l, int r);
// int main()
// {
//     int *iArr = new int[MAX];
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> iArr[i];
//     }

//     cout << findMaxSeq(iArr, 0, n - 1);

//     delete[] iArr;
//     return 0;
// }

// int findMaxSeq(int iArr[], int l, int r)
// {
//     int max = 0;
//     if (l == r)
//         return iArr[l];
//     int m = (l + r) / 2;
//     int ml = findMaxSeq(iArr, l, m);
//     int mr = findMaxSeq(iArr, m + 1, r);

//     int maxL = findMaxL(iArr, l, m);
//     int maxR = findMaxR(iArr, m + 1, r);
//     int mg = maxL + maxR;

//     max = ml > mr ? ml : mr;
//     max = max > mg ? max : mg;

//     return max;
// }

// int findMaxL(int iArr[], int l, int m)
// {
//     int max = 0, tmp = 0;
//     for (int i = m; i >= l; i--)
//     {
//         tmp += iArr[i];
//         max = max > tmp ? max : tmp;
//     }
//     return max;
// }

// int findMaxR(int iArr[], int m, int r)
// {
//     int max = 0, tmp = 0;
//     for (int i = m; i <= r; i++)
//     {
//         tmp += iArr[i];
//         max = max > tmp ? max : tmp;
//     }
//     return max;
// }

//C1:
// int main()
// {
//     int *iArr = new int[MAX];
//     int n, iMax = 0;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> iArr[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int s = 0;
//         for (int k = i; k < n; k++)
//         {
//             s += iArr[k];
//             if (s > iMax)
//                 iMax = s;
//         }
//     }

//     cout << iMax;

//     delete[] iArr;
//     return 0;
// }
