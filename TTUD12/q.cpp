// https://codeforces.com/group/Ir5CI6f3FD/contest/279102/problem/Q
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 1;
const int M = 1e5 + 1;
vector<int> adj[N];
vector<int> low(N), num(N,-1) , counted(N,-1);
vector<int> isBridge[N];
int cur = 0;
int c; // dem so luong cau

// thuat toan Tanjan
void findBrigde(int u, int daddy){
    low[u] = num[u] = ++ cur;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == daddy) continue;
        if(num[i] == -1){
            findBrigde(v,u);
            low[u] = min(low[u],low[v]);
        }else{
            low[u] = min(low[u],num[v]);
        }
        
        if(low[v] > num[u]){
            isBridge[u].push_back(v);
            isBridge[v].push_back(u);
        }
    }
}

// dem so cau
void countBridge(int u, int daddy){
    counted[u] == 1;
    int flag = 0;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == daddy) continue;
        if(counted[v] == 1) continue;
        for(int i = 0; i < isBridge[u].size(); i++){
            if(v == isBridge[u][i]) flag = 1; 
        }

        if(flag == 1){
            c++;
            cout << u << " " << v << endl;
            countBridge(v,u);            
        }
    }
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < m; i++){
       int u,v;
       cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }

   for(int i = 0; i < n; i++){
       if(num[i] == -1) findBrigde(i,0);
   }

    int res = 0;   
    for(int i = 0; i < n; i++){
        c = 1;
        if(counted[i] == -1) countBridge(i,0);
        res += (c-1)*(c-2)/2;
    }

    cout << res << endl;
   
   return 0;
}
