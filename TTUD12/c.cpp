// #include <iostream>
// #include <math.h>
// using namespace std;

// long long note[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// long long n[9] = {1, 1, 1, 2, 1, 2, 2, 2, 3};
// long long s[9] = {1, 1, 1, 2, 1, 2, 1, 1, 3};
// long long res[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     long long t;
//     cin >> t;
//     while (t--)
//     {
//         long long w,c;
//         cin >> w;
//         cin >> c;
//         if(w < 1000) continue;
//         w = w/1000;
//         w = w * pow(10,c);
//         while (w)
//         {

//             for (long long j = 15; j >= 0; j--)
//             {
//                 for (long long i = 8; i >= 0; i--)
//                 {
//                     if (w >= note[i] * pow(10, j))
//                     {
//                         w -= note[i] * pow(10, j);
//                         res[i]++;
//                     }
//                 }
//             }
//         }

//         int soTo = 0;
//         int soCach = 1;
//         for(int i = 0; i < 9; i++){
//             if(res[i] != 0) soTo += res[i] * n[i];
//         }

//         for(int i = 0; i < 9; i++){
//             if(res[i] != 0) soCach *= res[i] * s[i];
//         }
//         cout << soTo <<" "<< soCach << endl;
//     }

//     return 0;
// }


