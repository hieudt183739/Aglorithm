#include<iostream>
#include<vector>
#include <utility>
using namespace std;

const int N=10050;
int n,k,m;
int res=1e9;
vector<pair<int,int>> connected[N];

void dfs(int u,int daddy, int sum,int depth){
    if(depth==k){
        res=min(res,sum);return;
    }
    
    for(int i=0;i<connected[u].size();i++){
        if(connected[u][i].first==daddy)
            continue;
        else 
            dfs(connected[u][i].first,u,sum+connected[u][i].second,depth+1);
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
   
   for(int i=1;i<=n;i++){
       dfs(i,0,0,0);
   }

   cout<<res<<"\n";
   return 0;
}