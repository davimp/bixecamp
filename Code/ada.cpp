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
int n, m;
int cost[30];
int dp[MAX][MAX];
string a, b;

int main(){
    cin >> n >> m;

    fr(i, 26){
        cin >> cost[i];
    }

    cin >> a;
    cin >> b;

    /*dp[0][0] = 0;
    fr(j, m){
        if(a[0] == b[j]){
            dp[0][j] = cost[a[0] - 'a'];
        }
        else{
            dp[0][j] = dp[0][max(0, j-1)];
        }
    }*/

    frr(i, n){
        frr(j, m){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + cost[a[i-1] - 'a'];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][max(0, j-1)]);
            }
        }
    }

    cout << dp[n][m] << endl;

}
