#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
int q, n, m, c_road, c_lib;
vector<int> connected[N];
bool used[N];
vector<long> result;
long sum = 0;
int dem = 0;

void DFS(int u, int daddy){
    dem++;
    for(int i = 0; i < connected[u].size(); i++){
        int v = connected[u][i];
        if(v == daddy) continue;
        if(used[v] == 1) continue;
        used[v] = 1;
        DFS(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> q;
    while(q--){

        for(int i = 0; i < N; i++){
            used[i] = 0;
            for(int j = 0; j < connected[i].size(); i++){
                connected[i][j] = 0;
            }
        } 
        sum = 0;  
        dem = 0; 
              
        cin >> n >> m >> c_lib >> c_road;
        for(int i = 1; i <= m; i++){
            int u,v;
            cin >> u >> v;
            connected[u].push_back(v);
            connected[v].push_back(u);
        }

        if(c_lib <= c_road){
            sum = n * c_lib;
        }else{
            for(int i = 1; i <= n; i++){
                if(used[i] == 0){
                    used[i] = 1;
                    DFS(i, 0);
                    sum += c_lib + c_road * (dem - 1);
                    dem = 0;
                }
            }
        }
        result.push_back(sum);
    }
    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;
  
    return 0;
}