#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100050;
int n,m;
vector<int> connected[N];
int side[N];
bool visited[N];
int res = 1;

void DFS(int u, int s){
    visited[u] = 1;
    side[u] = s;
    for(int i = 0; i < connected[u].size(); i++){
        int v = connected[u][i];
        if(visited[v]){
            if(side[u] == side[v]) res = 0;
        }else{
            DFS(v,!s);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i,1);
    }
    
    cout << res << endl;
    return 0;
}