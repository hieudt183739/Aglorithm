// https://www.hackerrank.com/challenges/greedy-florist/problem
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int const N = 120;
int n, k;
int c[N];
int res = 0;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    sort(c + 1, c + n + 1);

    int start = 0;
    int dem = 0;

    for(int i = n; i; i--){
        res += c[i] * (start + 1);
        dem++ ;
        // cout << res << endl;
        if(dem % k == 0) start++ ;  
    }

    cout << res << endl;

    return 0;
}



