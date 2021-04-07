#include <iostream>
#include <queue>
#include<tuple>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
int n,x,col,a,b,rem; queue<tuple<int,int> > t[5];
int main(){
    cin>>n;
    rep(i,0,n) rep(j,0,n) t[(i+j)%2+1].push({i,j});
    rep(i,0,n*n){
        cin>>x;
        if(rem) {
            col=rem==x?3:rem;
            tie(a,b)=t[rem].front(); t[rem].pop();
        } else {
            col=1==x?2:1;
            tie(a,b)=t[col].front(); t[col].pop();
            if(t[col].empty()) rem=3-col;
        }
        cout<<col<<" "<<1+a<<" "<<1+b<<"\n";
        cout.flush();
    }
}