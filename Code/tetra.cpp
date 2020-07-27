#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e7 + 8;
const int MOD = 1e9 + 7;

int dp[4][MAX];
     
int main(){
    ll n;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < MAX; j++)
            dp[i][j] = 0;

    cin >> n;
    
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[2][0] = 0;
    dp[3][0] = 0;

    for(int j = 1; j <= n; j++){
        for(int i = 0; i < 4; i++){
            dp[i][j] = ((dp[(i+1)%4][j-1] + dp[(i+2)%4][j-1])%MOD + dp[(i+3)%4][j-1])%MOD;
        }
    }

    cout << dp[0][n] << endl;
}