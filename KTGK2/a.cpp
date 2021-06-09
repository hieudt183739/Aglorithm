#include<iostream>
using namespace std;

const int N = 100050;
int n;
int a[N];
int res = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i+1]) res ++;
    }
    cout << res + 1 << endl;
    return 0;
}

