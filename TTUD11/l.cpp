#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100010;
int n,m;
vector<pair<int,int>> connected[N];
int s,t;
bool used[N];
long long d[N]; // d[v]: khoang cach tu s den v

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        connected[u].push_back({v,w});
    }
    cin >> s >> t;
    
    priority_queue<pair<long long, int>> q;
    for(int i = 1; i <= n; i++){
        d[i] = 1e18;
    }
    d[s] = 0;

    q.push({0,s});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(used[u]) continue;
        used[u] = 1;
        for(int i = 0; i < connected[u].size(); i++){
            int v = connected[u][i].first;
            int w = connected[u][i].second;
            if(d[v] > d[u] + w){
               d[v] = d[u] + w;
               q.push({-d[v],v}); // vi su dung priority_queue
           }
        }
    }
    if(!used[t]) cout << -1 << endl;
    else cout << d[t] << endl;

    return 0;
}