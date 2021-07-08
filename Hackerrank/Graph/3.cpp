// https://www.hackerrank.com/challenges/components-in-graph/problem
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5;
pair<int, int> edge[N];
int n;
int maxResult = 0;
int minResult = 1e6;

struct DSU{
    int root[N];
    int size[N];
    DSU(){
        for(int i = 1; i <= 2 * n; i++){
            root[i] = i;
            size[i] = 1;
        }
    }

    int getRoot(int u){
        if(root[u] == u) return u;
        else return root[u] = getRoot(root[u]);
    }
    void unite(int u, int v){
        u = getRoot(u);
        v = getRoot(v);
        if(u == v) return;
        root[u] = v;
        size[v] += size[u];
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        edge[i] = make_pair(u, v);
    }    

    DSU dsu;
    for(int i = 1; i <= n; i++){
        int u, v;
        u = edge[i].first;
        v = edge[i].second;
        dsu.unite(u, v);
    }

    for(int i = 1; i <= 2 * n; i++){
        int x = dsu.size[dsu.getRoot(i)];
        maxResult = max(maxResult, x);
        if(x >= 2) minResult = min(minResult, x);
        
    }

    cout << minResult << " " << maxResult << endl;

    return 0;
}