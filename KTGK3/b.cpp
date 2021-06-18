#include<iostream>
#include<utility>
#include<vector>
using namespace std;

const int N = 100050;
int n,q;
vector<pair<int,int>> connected[N];
int cut[N];

void dfs(int u, int j, int daddy,int &sum){
    for(int i = 0; i < connected[u].size(); i++){
        if(i == j) continue;
        int v = connected[u][i].first;
        if(v == daddy || v == 0) continue;
        dfs(v,j,u,++sum);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int u,v;
        cin >> u >> v;
        connected[u].push_back({v,i});
        connected[v].push_back({u,i});
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> cut[i];
    }

    for(int c = 1; c <= q; c++){
        int i;
        int j;
        int v;
        int k;
        int flag = 0;
        for(i = 1; i <= n; i++){
            for(j = 0; j <= n; j++){
                if(connected[i][j].second == cut[c]){
                    v = connected[i][j].first;
                    connected[i][j].first = 0;
                 k = 0;
                    while(1){
                        if(connected[v][k].second == cut[c]){
                            connected[v][k].first = 0;
                            break;
                        } 
                        k++;
                    }
                    flag = 1;
                    break;
                }               
            }
            if (flag == 1) break;
        }
        int sumX,sumY;
        sumX = 1;
        sumY = 1;
        dfs(i,j,0,sumX);
        dfs(v,k,0,sumY);
        cout << sumX << " " << sumY << endl;

    }
    return 0;
}

