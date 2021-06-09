#include<iostream>
using namespace std;

const int N = 22;
int connected[N][N];
int used[N];
int n,m;
int res = 1e9;

bool isDocLap(){
    for(int i = 1; i <= n; i++){
        int flag = 1;
        if(!used[i]){
            for(int j = 1; j <= n; j++){
                if(used[j] && connected[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    return true;
}

void Try(int u, int size){
    if(u > n){
        if(isDocLap()) res = min(res,size);
        return;
    }
    used[u] = 0;
    Try(u + 1, size);

    int flag = 1; 
    for(int i = 1; i < u; i++){
        if(used[i] && connected[u][i]) flag = 0;
    }    
    if(flag) {
        used[u] = 1;
        Try(u + 1, size + 1);
    }  
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        connected[u][v] = 1;
        connected[v][u] = 1;
    }    

    Try(1,0);
    cout << res << endl;
    return 0;
}