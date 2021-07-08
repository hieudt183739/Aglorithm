#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 1;
int n, q;
pair<int, int> edge[N];
int id[N];
bool used[N];
long long res[N];

// DSU luu rung
struct DSU{
    int root[N]; // goc cua cay
    int size[N]; // kich thuoc cua cay 
    DSU(){
        for(int i = 1; i <= n; i++){
            root[i] = i;
            size[i] = 1;
        }
    }
    // tim goc cua 1 cay
    int getRoot(int u){
        if(root[u] == u) return u;
        return root[u] = getRoot(root[u]);
    }
    // hop 2 cay 
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
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge[i] = make_pair(u, v);
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> id[i];
        used[id[i]] = 1;
    }    
    
    DSU dsu;
    for(int i = 1; i <= n - 1; i++){
        if(used[i] == 0){
            dsu.unite(edge[i].first, edge[i].second);
        }
    }
    for(int i = q; i; i--){
        int u, v;
        u = edge[id[i]].first;
        v = edge[id[i]].second;
        res[i] = 1ll * dsu.size[dsu.getRoot(u)] * dsu.size[dsu.getRoot(v)]; 
        dsu.unite(u, v); // hop 2 cay lai voi nhau
    }
    for(int i = 1; i <= q; i++){
        cout << res[i] << endl;
    }
    

    return 0;
}