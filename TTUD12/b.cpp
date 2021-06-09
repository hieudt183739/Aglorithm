// https://codeforces.com/group/Ir5CI6f3FD/contest/281925/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>t;
int n;

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   int res = 0;
   cin >> n;
   for(int i = 0; i < n; i++){
       int u;
       cin >> u;
       t.push_back(u);
   }   
   sort(t.begin(),t.end(),greater<int>()); 
   for(int i = 0; i < t.size(); i++){
       t[i] += i + 1;
       res = max(t[i],res);
   }

    cout << res + 1 << endl;


   return 0;
}