#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
int a[N];
long long dp[N];
vector<int> res;
int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    dp[n + 1] = dp[n + 2] = 0;
    for(int i = n; i; i--){
        dp[i] = max(dp[i + 1], dp[i + 2] + a[i]);
    }
    int cur = 1;
    while(cur <= n && dp[cur] != 0){
        if(dp[cur] == dp[cur + 2] + a[cur]){
            res.push_back(cur);
            cur += 2;
        }else cur++;
    }
    cout << dp[1] << "\n";
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    cout << "\n";
    
    return 0;
}