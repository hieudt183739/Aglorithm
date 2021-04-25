#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

const int N=10050;
const int K=2010;
int n,k,m;
int res=1e9;
int dp[N][K]; // dp[1][2]: đường đi nhỏ nhất có từ gốc 1 tới độ xâu là 2

vector<pair<int,int>> connected[N];

void dfs(int u,int daddy){
    fill(dp[u],dp[u]+k+1,1e9);
    dp[u][0]=0;
    
    for(int i=0;i<connected[u][i].first;i++){
        int first=connected[u][i].first;
        int second=connected[u][i].second;
        
        if(first==daddy)continue;
        dfs(first,u);
        
        //update res
        for(int j=0;j<k;j++){
            res=min(res,dp[u][k-j-1]+dp[first][j]+second);
        }
        //update dp[][]
        for(int j=0;j<k;j++){
            dp[u][j+1]=min(dp[u][j+1],dp[first][j]+second);
        }
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   cin>>n>>k;
   cin>>m;
   for(int i=1;i<=m;i++){
       int u,v,w;
       cin>>u>>v>>w;
       connected[u].push_back({v,w});
       connected[v].push_back({u,w});
   }
   
   dfs(1,0);
   cout<<res<<endl;

   return 0;
}