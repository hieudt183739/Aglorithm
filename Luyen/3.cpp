// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// int integerReplacement(int n){
//     if(n == 1) return 0;
//     if(n % 2 == 0) return 1 + integerReplacement(n / 2);
//     return 1 + min(1 + integerReplacement(n + 1),integerReplacement(n - 1));
// }

// int main(){
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     int n;
//     cin >> n;

//     cout << integerReplacement(n) << endl; 
    
//     return 0;
// }



// PD
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

map<int, int> memory;
int intergerReplacement(int n){
    if(n == 1) return 0;
    if(memory.find(n) != memory.end()){
        return memory[n];
    }

    int res = 0;
    if(n % 2 == 0) res = 1 + intergerReplacement(n / 2);
    else{
        res = 1 + min(intergerReplacement(n + 1), intergerReplacement(n - 1));
    }
    memory[n] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;

    cout << intergerReplacement(n) << endl;
    return 0;
}

// https://leetcode.com/problems/integer-replacement/