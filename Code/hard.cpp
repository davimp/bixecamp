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
#define INF 1000000000000000
const int MAX = 112345;
ll n;
ll dp[MAX][2], cost[MAX];
string r[MAX], s[MAX];

int main(){
	fr(i, MAX)
		fr(j, 2)
			dp[i][j] = INF;


	cin >> n;
	fr(i, n)
	{
		cin >> cost[i];
	}

	
	fr(i, n)
	{
		cin >> s[i];
		r[i] = s[i];
		reverse(r[i].begin(),r[i].end());
	}

	dp[0][0] = 0;
	dp[0][1] = cost[0];

	frr(i, n-1)
	{	/* sem reverter */
		if(s[i] >= s[i-1])
			dp[i][0] = dp[i-1][0];
		if(s[i] >= r[i-1])
			dp[i][0] = min(dp[i][0],dp[i-1][1]);

		/* revertendo */
		if(r[i] >= s[i-1])
			dp[i][1] = dp[i-1][0] + cost[i];
		if(r[i] >= r[i-1])
			dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i]);		
	}

	ll ans;
	ans = min(dp[n-1][0], dp[n-1][1]);

	
	if(ans == INF || ans < 0)
		cout << -1 << endl;
	else
		cout << ans << endl;
}
