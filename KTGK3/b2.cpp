#include<iostream>
#include<vector>
using namespace std;

const int N = 100050;
int n,q;
vector<vector<int>> adj[N];
int cut[N];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u,v;
        cin >> u >> v;
        adj[i][u].push_back(v);
        adj[i][v].push_back(u);
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> cut[i];
    }
    
    for(int c = 1; c <= q; c++){
        for(int i = 1; i <= n; i++) adj[cut[c]][i] = 0;
        
    }
    
}