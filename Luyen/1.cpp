// https://www.facebook.com/code.cung.rr/videos/186932330035217/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

int N;
int K;
int dp[33][2][33][2], d[33];

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    while(cin >> N >> K){
        vector<int> bits;
        memset(d, 0, sizeof(d));

        while(N > 0){
            bits.push_back(N % 2);
            N = N / 2;
        }

        if(bits.empty()) bits.push_back(0);
        if(K > bits.size()){
            cout << 0 << endl;
            continue;
        }

        for(int i = 1; i <= bits.size(); i++){
            d[i] = bits[bits.size() - i];
        }
        for(int i = 1; i <= bits.size(); i++) cout << d[i];
        cout << endl;

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;
        for(int i = 0; i < bits.size(); i++)
            for(int lower = 0; lower <= 1; lower++)
                for(int k = 0; k <= i; k++)
                    for(int positive = 0; positive <= 1; positive++)
                        for(int digit = 0; digit <= 1; digit++){

                            int cur = dp[i][lower][k][positive];
                            
                            if(!lower && digit > d[i + 1]) continue;
                            int lower2 = lower || (digit < d[i + 1]);

                            int k2 = k;
                            if(positive && digit == 0) k2++;
                            
                            int positive2 = positive || (digit == 1);

                            dp[i + 1][lower2][k2][positive2] += dp[i][lower][k][positive];
                        }
        int res = 0;
        for(int lower = 0; lower <= 1; lower++){
            res += dp[bits.size()][lower][K][1];
        }
        if(K == 1) res++;
        cout << res << endl;
    }
    
    return 0;
}
 


   