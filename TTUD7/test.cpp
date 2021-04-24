#include<iostream>
#include<cstring>
using namespace std;
const int Max=1000;

int m,k;
int p[Max];
int kq[Max];

int check(long long x){
    int k1=k;
    int res=1;
    int tmp=0;
    int flag=1;
    memset(kq,0,sizeof(kq));

    for(int i=m;i>0;i--){
        if(p[i]>x)return 0;
        if(i==k1){
            res++;
            k1--;
            kq[i]=1;
        }else if(tmp+p[i]<=x){
            tmp+=p[i];
            if(flag){flag=0;k1--;}
        }else{
            res++;
            kq[i]=1;
            tmp=p[i];
            flag=1;
        }
    }
    return res<=k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
       cin>>m>>k;
       for(int i=1;i<=m;i++){
           cin>>p[i];
       }

       long long low=0,high=1e10;
       while(high-low>1){
           long long mid=(high+low)>>1;
           if(check(mid))high=mid;
           else low=mid;
       }

       check(high);
       for(int i=1;i<=m;i++){
           cout<<p[i]<<" ";
           if(kq[i])cout<<" / ";
       }
       cout<<endl;
    }

    return 0;
}