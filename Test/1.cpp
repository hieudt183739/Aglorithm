#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> c;
long long dp[251][51];
int m,n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    for(int i = 1; i <= 250; i++){
        for(int j = 1; j <= 50; j++)
           dp[i][j] = 0;
    }
   
    for(int i = 2; i <= 250; i++){
        dp[2][i] = 1;
    }
    
    
    return 0;
}