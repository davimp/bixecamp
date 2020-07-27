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
const int MAX = 112345;
int a[MAX];
int dp[33][MAX][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	fr(i, n){
		cin >> a[i];
	}


	fr(j, n){
		dp[30][j][0] = dp[30][j][1] = 0;
	}

	for(int i = 29; i >= 0; i--){
		for(int j = 0; j < n; j++){
			int aux = (a[j]>>i)&1;
			dp[i][j][0] = max(dp[i+1][j][0], dp[i+1][j][1])*2;
			dp[i][j][1] = max(dp[i+1][j][0], dp[i+1][j][1])*2;

			if(aux) dp[i][j][0]++;
			else dp[i][j][1]++;
		}
	}
	
	int ans;
	ans = 1e9 + 1;
	fr(i, n){
		ans = min({ans, dp[0][i][0], dp[0][i][1]});
	}


	cout << ans << endl;

}
