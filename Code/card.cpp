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
const int MAX = 1123456;
int tc, n;
int dp[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	int cnt = 0;
	dp[0] = 0;
	for(int i = 1; i < MAX; i++){
		if(i - dp[i-1] == 2+3*cnt){
			cnt++;
			dp[i] = dp[i-1]+1;
		}
		else{
			dp[i] = dp[i-1];
		}
	}
	while(tc--){
		cin >> n;
		cout << dp[n] << endl;
	}
}
