#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define f first
#define s second
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 2123;
int dp[MAX][2];
int n, k, d;
int nivel;

int main(){
    fr(i, MAX)
        fr(j, 2)
            dp[i][j] = 0;
    
    cin >> n >> k >> d;

    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j >= d){
                dp[i+j][1] = ((dp[i+j][1] + dp[i][1])%MOD + dp[i][0])%MOD;
            }
            else {
                dp[i+j][0] = (dp[i+j][0] + dp[i][0])%MOD;
                dp[i+j][1] = (dp[i+j][1] + dp[i][1])%MOD;
            }
        }
    }

    cout << dp[n][1] << endl;

}
