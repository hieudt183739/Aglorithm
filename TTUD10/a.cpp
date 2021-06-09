#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];             // mang 2 chieu
vector<int> visitted(N,-1);
int current = 0;
int component = 0;

void dfs(int u, int daddy){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == daddy) continue;
        if(visitted[v] == -1){
            visitted[v] = 1;
            dfs(v,u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    
    for(int i = 1; i <= n; i++){
        if(visitted[i] == -1){
            dfs(i, 0);
            component++;
        }
    }

    cout << component << endl;

    return 0;
}