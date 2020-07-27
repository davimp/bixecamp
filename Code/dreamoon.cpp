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
int tc;
int d, m;


void solve(){
	ll ans, aux;
	ans = 1;

	cin >> d >> m;

	for(int i = 0; i < 30; i++){
		if((1<<i) > d) break;
		aux = min((1<<(i+1))-1, d) - (1<<i) + 2;
		aux = aux%m;
		ans = (ans*aux)%m;
		if(ans < 0) ans += m;
	}
	ans--;
	if(ans < 0) ans += m;
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		solve();
	}
}
