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
int tc;
int n;
int a[MAX], b[MAX];
int ans, delta, dif;

void solve(){
	delta = ans = dif = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	b[0] = a[0];

	for(int i = 1; i < n; i++){
		if(a[i] >= b[i-1]){
			b[i] = a[i];
		}
		else{
			b[i] = b[i-1];
			if(b[i] - a[i] > dif) dif = b[i] - a[i];
		}
	}
	/*cout << endl;*/
	/*fr(i, n) cout << b[i] << " ";
	cout << endl;*/
	while(delta < dif){
		delta += (1 << ans);
		ans++;
	}

	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		solve();	
	}
}
