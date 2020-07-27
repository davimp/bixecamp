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
#define MOD 998244353
const int MAX = 212345;
ll n;
ll pot[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	pot[0] = 1;

	frr(i, n){
		pot[i] = (10 * 1ll * pot[i-1])%MOD;
	}

	ll ans, aux;
	frr(i, n-1){
		ans = 0;
		ans = (180*pot[n-i-1])%MOD;
		aux = ((n-1-i)*9*9*10)%MOD;
		ans = (aux*pot[n-2-i] + ans)%MOD;
		cout << ans << " ";
	}
	cout << 10 << endl;
}
