#include <iostream>
#include <queue>
using namespace std;

int n, i, j, a, x, y;
vector<pair<int, int> > c[2];
 
void calc() {
  cin >> a;
  x = (!c[1].empty() && a != 1) || c[0].empty();
  y = x ? (a == 1 ? 3 : 1) : (a == 2 ? 3 : 2);
  printf("%d %d %d\n", y, c[x].back().first, c[x].back().second);
  cout.flush();
  c[x].pop_back();
}
 
int main() {
  cin >> n;
  for (i = 1 ; i <= n ; i++)
    for (j = 1 ; j <= n ; j++)
      c[(i + j) & 1].push_back(make_pair(i, j));// i+j chan-->c[0]
  for (i = 1; i <= n*n ; i++)
    calc();
}