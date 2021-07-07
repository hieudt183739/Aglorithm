//https://www.hackerrank.com/challenges/construct-the-array/problem
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
const unsigned long long MOD = 1e9 + 7;

int n,k,x;
unsigned long long dp[N][3];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k >> x;
    dp[1][1] = 1;
    dp[1][2] = 0;

    for(int i = 2; i <= n; i++){
        dp[i][1] = (dp[i - 1][2] * (k - 1)) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][2] * (k - 2)) % MOD;
    }

    if(x == 1) cout << dp[n][1] << endl;
    else cout << dp[n][2] << endl;
    
    return 0;
}


// dp[5][3] = dp[4][1] + dp[4][2] = dp[3][2] + dp[3][3] + dp[3][1] +dp[3][3]

// = dp[2][1] + dp[2][3] + 2 * ( dp[2][1] + d[2][2]) + dp[2][2] + dp[2][3]

// = dp[1][1] + 3 * dp[1][1] + dp[1][1] 

// dp[5][2] = dp[4][1] + dp[4][3] = dp[3][2] + dp[3][3] + dp[3][1] + dp[3][2]
// = 2 * ( dp[2][1] + dp[2][3]) + dp[2][1] + dp[2][2] + dp[2][2] + dp[2][3]

// dp[5][3] % 10 = (dp[4][1] + dp[4][2]) % 10
// dp[5][1] % 10 = dp[4][2] * 2 % 10
//                 dp[3][1] + dp[3][3] ) * 2 % 10



