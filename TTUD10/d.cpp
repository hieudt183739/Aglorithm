#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int N = 100050;
int n,m;
vector<int> connected[N];
vector<int> num(N,-1),low(N);
stack<int> st; 
bool scc[N];// scc[v] = 1. v da nam trong 1 thanh phan lien thong manh nao do
int current = 0;
int num_scc = 0;

void Tacjan(int u){
    num[u] = low[u] = ++ current;
    st.push(u);
    for(int i = 0; i < connected[u].size(); i++){
        int v = connected[u][i];
        if(scc[v] == 1) continue;
        if(num[v] != -1) low[u] = min (low[u],num[v]);
        else{
            Tacjan(v);
            low[u] = min(low[u],low[v]);
        }
    }
    // xd thanh phan lien thong manh
    if(num[u] == low[u]){
        num_scc++;
        while(1){
            int v = st.top();
            st.pop();
            scc[v] = 1;
            if(u == v) break;
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
    }

    for(int i = 1; i <= n; i++){
        if(num[i] == -1) Tacjan(i);
    }

    cout << num_scc << endl;
    return 0;
    
}