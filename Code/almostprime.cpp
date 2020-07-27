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
ll tc;
ll l, r;
ll lp[MAX+2];
vector<ll> pr;

void primes(){
	for (ll i=2; i <= MAX; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (ll j=0; j<(ll)pr.size() && pr[j]<=lp[i] && i*pr[j]<=MAX; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	primes();
	cin >> tc;
	while(tc--){
		cin >> l >> r;
		ll cnt, aux;
		ll ans; ans = 0;
		for(ll i = 0; i < pr.size() && pr[i]*pr[i] <= r; i++){
			cnt = 0;
			aux = pr[i];
			while(aux <= r){
				aux *= pr[i]; if(aux >= l) cnt++;
			}
			if(cnt >= 2) ans += (cnt-1);
		}

		cout << ans << endl;
	}
}
