#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e6 + 1;
int n, a[N];
int l[N],r[N];
int stt[N];
unsigned long long result = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l[i] = i - 1;
        r[i] = i + 1;
        stt[i] = i;
    }    

    sort(stt + 1, stt + n + 1, [&](int u, int v){
        if(u != v) return a[u] > a[v];
        return u < v;
    });
    
    for(int i = 1; i <= n; i++){
        int u = stt[i];
        cout << i << " " << u << endl;
        result += a[u] + a[l[u]] + a[r[u]];
        r[l[u]] = r[u];
        l[r[u]] = l[u]; 
    }
    
    cout << result << endl;


    return 0;
}

