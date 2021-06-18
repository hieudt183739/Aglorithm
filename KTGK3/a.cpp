#include<iostream>
using namespace std;

const int N = 1010;
int n;
int a[N][N];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i != j && a[i][j] == 0 && a[j][i] == 0) || ((i == j ) && a[i][j] !=0)){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    
    cout << 1 << endl;
    return 0;
}