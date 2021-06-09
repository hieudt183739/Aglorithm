#include<iostream>
using namespace std;

int note[6]={500,100,50,10,5,1};

int find(int tien){
    for(int i=0;i<6;i++){
      if(note[i]<=tien)  return note[i];
    }
    return 0;
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   int tien;
   int res=0;
   cin >> tien;
   tien=1000-tien;
   while(tien > 0){
       int x=find(tien);
       if(x==0) return 0;
       res++;
       tien-=x;
   }
   
   cout << res <<endl;


   return 0;
}