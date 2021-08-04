#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 1;
int n, q;
pair<int, int> edge[N];
int id[N];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        edge[i] = make_pair(u, v);    
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> id[i];
    }
    
    return 0;
}