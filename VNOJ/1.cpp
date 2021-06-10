// https://oj.vnoi.info/problem/baric
#include<iostream>
#include<vector>
using namespace std;

const int N = 110;
int n,e;
int m[N];
int res = 1e9;
int sum = 1e9;
int used[N];

int check(){
  int sum = 0;
  int count = 0;
  for(int i = 1; i <= n; i++){
    if(used[i] == 0){
      int j,k;
      j = i + 1;
      k = i - 1;
      while(j <= n && used[j] == 0) j++;
      while(k >= 1 && used[k] == 0) k--;
      if(k == 0) sum += 2 * abs(m[j] - m[i]);
      else if(j > n) sum += 2 * abs(m[k] - m[i]);
      else sum += abs(2 * m[i] - (m[j] + m[k]));
    }else count++;
  }
  
  if(sum > e || count > e) return -1;
  return sum;
  
}

void Try(int u, int quantity){
  if(u > n && quantity != 0){
    int tmp = check();
    if(tmp != -1) {
      if(res > quantity){
        res = quantity;
        sum = tmp;
      }
      else if(res == quantity) sum = min(sum,tmp);
    }
    return;
  }
  
  used[u] = 0;
  Try(u + 1, quantity);
  
  used[u] = 1;
  Try(u + 1, quantity + 1);  
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  
  cin >> n >> e;
  for(int i = 1; i <= n; i++){
    cin >> m[i];
  }
  Try(1,0);
  cout << res << " " << sum << endl;
}

