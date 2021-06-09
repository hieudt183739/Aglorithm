#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100010;
int n,m;
vector<pair<int,int>> connected[N];
bool used[N];
priority_queue<pair<int,int>> q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        connected[u].push_back({v,w});
        connected[v].push_back({u,w});
    }

    q.push({0,1});
    long long res = 0;
    while(!q.empty()){
        auto [d,u] = q.top();
        d = - d;
        q.pop();
        if(used[u]) continue;
        used[u] = true;
        res += d;
        for(auto [v,w] : connected[u]){
            q.push({-w,v});
        }
    }
    cout << res << endl;
    return 0;
}