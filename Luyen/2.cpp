#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

int a, b, d, k;
int n[15];
int dp[17][17][10][2][2];

int get(int u, int d, int k){
    vector<int>bits;
    while(u > 0){
        bits.push_back(a % 10);
        u = u / 10;
    }
    for(int i = 1; i <= bits.size(); i++){
        n[i] = bits[bits.size() - i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0][0] = 1;
    for(int i = 0; i < bits.size(); i++)
        for(int bad = 0; bad <= k; bad++)
            for(int last = 0; last <= 9; last ++)
                for(int lower = 0; lower <= 1; lower++)
                    for(int positive = 0; positive <= 1; positive++)
                        for(int next = 0; next <= 9; next++){

                            int cur = dp[i][bad][last][lower][positive];
                            if(!lower && next > n[i + 1]) continue;
                            
                            int bad2 = bad;
                            if(positive && (abs(last - next)) > d) bad2++; 

                            int last2 = next; 

                            int lower2 = lower || (next < n[i + 1]); 

                            int positive2 = positive || (next > 0); 

                            dp[i + 1][bad2][last2][lower2][positive2] += dp[i][bad][last][lower][positive];


                        }
    cout << " ///// " << endl;
    int res = 0;
    for(int bad = 0; bad <= k; bad++)
        for(int last = 0; last <= 9; last++){
            cout << dp[bits.size()][bad][last][1][1] << endl;
            res += dp[bits.size()][bad][last][1][1];
        }
/*
    cout << " ///// " << endl;
    for(int i = 0; i <= bits.size(); i++)
        for(int bad = 0; bad <= k; bad++)
            for(int last = 0; last <= 9; last ++)
                for(int lower = 0; lower <= 1; lower++)
                    for(int positive = 0; positive <= 1; positive++){
                        cout << i << " " << bad << " " << last << " " << lower << " " << positive << " " << dp[i][bad][last][lower][positive] << endl;
                    }
*/
    return res;

}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> a >> b >> d >> k;
    cout << get(b + 1, d, k) - get(a, d, k) << endl;
    return 0;
}



