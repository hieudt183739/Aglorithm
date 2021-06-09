#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    vector<vector<int>>connected(f+1);
    for(int i = 1; i <= f; i++){
        if(i + u <= f) connected[i].push_back(i + u);
        if(i - d >= 1) connected[i].push_back(i - d);
    }

    queue<int> q;
    vector<bool> used(f + 1,false);
    vector<int> shortest(f + 1, -1);

    q.push(s);
    used[s] = 1;
    shortest[s] = 0;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < connected[u].size(); i++){
            int v = connected[u][i];
            if(!used[v]){
               shortest[v] = shortest[u] + 1;
               q.push(v);
               used[v] = 1;
            }
        }
    }

    if(used[g]) cout << shortest[g] << endl;
    else cout << "use the stairs" << endl;
    
    return 0;
}