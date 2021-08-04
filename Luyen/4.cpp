#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5 + 10;
int num[N];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    int res = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        res += num[i] * i;
        sum += num[i];
    }
    int tmp = res;
    for(int i = n -1; i >= 1; i--){
        tmp = tmp - num[i] * (n - 1) + sum - num[i];
        res = max(res, tmp); 
    }
    cout << res << endl;
    return 0;
}
// https://leetcode.com/problems/rotate-function
// f(0) = num[0] x 0 + num[1] x 1 + num[2] x 2 + num[3] x 3
// f(1) = num[3] x 0 + num[0] x 1 + num[1] x 2 + num[2] x 3 = f(0) - num[3] x 3 + num[0] + num[1] + num[2] 
//      = f(0) - num[3] x 3 + sum -num[3]
// f(2) = num[2] x 0 + num[3] x 1 + num[0] x 2 + num[1] x 3 = f(1) - num[2] x 3 + num[3] + num[0] + num[1]
//      = f(1) - num[2] x 3 + sum - num[2];

