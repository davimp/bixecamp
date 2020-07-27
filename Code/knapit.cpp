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
int s, n;
int w[MAX], v[MAX];
int dp[MAX][MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> n;
	fr(i, n)
	{
		cin >> w[i] >> v[i];
	}
	

	frr(i, n)
	{
		frr(j, s)
		{
			if(w[i-1] <= j)
			{
				dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][s] << endl;
}




