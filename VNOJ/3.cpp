//https://www.hackerrank.com/challenges/sherlock-and-cost/problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

const int N = 1e5 + 1;
int B[N];
int dp[N][2];
int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> B[i];
        }

        for(int i = 1; i <= n -1; i++){
            dp[i + 1][0] = max(dp[i][0],dp[i][1] + abs(1 - B[i]));
            dp[i + 1][1] = max(dp[i][0] + abs(B[i + 1] - 1),dp[i][1] + abs(B[i + 1] - B[i]));
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}