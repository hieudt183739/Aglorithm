// https://www.hackerrank.com/challenges/coin-change/problem

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> c;
long long dp[251][51];
bool mark[251][51];
int m,n;

// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
    
//     cin >> n >> m;
//     for(int i = 1; i <= m; i++){
//         int u;
//         cin >> u;
//         c.push_back(u);
//     }
     
//     sort(c.begin(), c.end());
//     for(int i = 1; i <= 250; i++){
//         for(int j = 1; j <= 50; j++)
//            dp[i][j] = 0;
//     }
//     for(int i = 1; i <= 250; i++){
//         if(i % c[0] == 0) dp[i][1] = 1;
//         else dp[i][1] = 0;
//     }
//     for(int i = 2; i <= 50; i++){
//         dp[c[0]][i] = 1;
//     }
    
//     for(int i = 2; i <= n; i++){
//         for(long unsigned int m = 2; m <= c.size() ; m++){
//             if(i > c[m - 1]){
//                 dp[i][m] = dp[i][m - 1] + dp[i - c[m - 1]][m];
//             }
//             else if(i == c[m - 1])
//                 dp[i][m] = dp[i][m - 1] + 1;
//             else{
//                 dp[i][m] = dp[i][m - 1];
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++)
//     for(int j = 1; j <= m; j++)
//     cout << i << " " << j << " " << dp[i][j] << endl;

//     cout << dp[n][c.size()] << endl;
//     return 0;
// }

long long Try(int n, int m){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(m == 0) return 0;
    
    if(mark[n][m] == false){
        dp[n][m] = Try(n, m - 1) + Try(n - c[m -1], m);
        mark[n][m] = true;
    }

    return dp[n][m];    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u;
        cin >> u;
        c.push_back(u);
    }
    for(int i = 1; i <= 50; i++)
        dp[0][i] = 1;
    Try(n,m);
    cout << dp[n][m] << endl;
    return 0;
    
}