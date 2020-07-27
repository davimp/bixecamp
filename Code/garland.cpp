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
#define INF 1e9
const int MAX = 112;
int memo[MAX][MAX][2];
int n;
int a[MAX];
int zeros, uns;

int dp(int j, int k, int last)
{
	int i = j + k;
	if(j > zeros || k > uns) return INF;
	if(i >= n) return 0;

	int &pdm = memo[j][k][last];
	if(pdm != -1) return pdm;
	
	if(i == 0)
	{
		if(a[0] == -1) return pdm = min(dp(j + 1, k, 0), dp(j, k + 1, 1));
	    if(a[0] == 1) return pdm = dp(j, k+1, 1);
		return pdm = dp(j+1, k, 0);
	}

	if(a[i] == 1)
	{
		if(last) return pdm = dp(j, k + 1, 1);
		return pdm = dp(j, k + 1, 1) + 1;
	}
	else if(a[i] == 0)
	{
		if(last) return pdm = dp(j + 1, k, 0) + 1;
		return pdm = dp(j + 1 , k, 0);
	}
	else
	{
		if(last)
		{
			return pdm = min(dp(j, k + 1, 1), dp(j + 1, k, 0) + 1);
		}
		else
		{
			return pdm = min(dp(j, k + 1, 1) + 1, dp(j + 1, k, 0));
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fr(j, MAX)
		fr(k, MAX)
			fr(l, 2)
				memo[j][k][l] = -1;
	
	cin >> n;
	zeros = n/2;
	uns = n - zeros;
	 
	/*cout << zeros << " and " << uns << endl;*/
	fr(i, n)
	{
		cin >> a[i];
		if(a[i] != 0)
		{
			a[i] = a[i]%2;
		}
		else
		{
			a[i] = -1;
		}
	}
	int ans = dp(0, 0, 0);
	cout << ans << endl;
}
