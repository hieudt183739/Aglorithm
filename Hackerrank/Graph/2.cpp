// https://kienthuc24h.com/cau-truc-du-lieu-disjoint-sets/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e4 + 1;
vector<bool> result;
struct DSU{
    int root[N];
    int size[N];
    DSU(){
        for(int i = 1; i <= N; i++){
            root[i] = i;
            size[i] = 1;
        }
    }

    int getRoot(int u){
        if(root[u] == u) return u;
        return root[u] = getRoot(root[u]);
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
    
    DSU dsu;
    int p, x, y, z;
    cin >> p;
    for(int i = 1; i <= p; i++){
        cin >> x >> y >> z;
        if(z == 1){
            dsu.unite(x, y);
        }else if(z == 2){
            if(dsu.getRoot(x) == dsu.getRoot(y)) result.push_back(1);
            else result.push_back(0);
        }
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }

    return 0;
}