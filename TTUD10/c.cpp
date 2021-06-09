// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// const int N = 100050;
// int n,m,res;
// vector<int> connected[N];
// bool visited[N];
// int color[N];

// void BFS(int u){
//     queue<int> q;
//     q.push(u);
//     visited[u] = 1;

//     while(!q.empty()){
//         int tmp = q.front();
//         q.pop();

//         for(int i = 0; i < connected[tmp].size(); i++){
//             int v = connected[tmp][i];
//             if(!visited[v]){
//                 visited[v] = 1;
//                 q.push(v);
//             }
//         }
//         cout << tmp << endl;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
    
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int u,v;
//         cin >> u >> v;
//         connected[u].push_back(v);
//         connected[v].push_back(u);
//     }

//     BFS(1);

//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

const int N = 100010;
vector<int> connected[N];
vector<int> low(N), num(N, -1);
bool articulation[N];
int brigde = 0;
int current = 0;
int root = 0;
int children = 0;

void Tacjan(int u, int daddy){
    low[u] = num[u] = ++current;
    for(int i = 0; i < connected[u].size(); i++){
        int v = connected[u][i];
        if(v == daddy) continue;
        if(num[v] != -1){
            low[u]=min(low[u],num[v]);
        }else{          
            Tacjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v] > num[u]) brigde++;          
            
            if(low[v] >= num[u]) articulation[u] = 1;          
 
            if(u == root) children++;           
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < m; i++){
       int u,v;
       cin >> u >> v;
       connected[u].push_back(v);
       connected[v].push_back(u);
   }
    for(int i=1;i<=n;i++){
       if(num[i]==-1){
           root = i;
           children = 0;
           Tacjan(i,-1);
           articulation[root] = children > 1;
       }
    }
    
   int arti = 0;
   for(int i = 0; i <= n; i++) arti += articulation[i];
   cout << arti << " " << brigde << endl;


   return 0;
}