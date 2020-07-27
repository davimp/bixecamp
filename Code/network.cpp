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
ll n, m;
ll aux;
ll ans;
vector<ll> a, b;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	fr(i, n){
		cin >> aux;
		a.pb(aux);
	}
	fr(i, m){
		cin >> aux;
		b.pb(aux);
	}

	fr(i, n){
		int city = a[i];
		auto tower = lower_bound(b.begin(), b.end(), city);
		if(tower == b.end()) aux = LONG_LONG_MAX;
		else aux = *tower - city;
		if(tower != b.begin()){
			tower--;
			aux = min(aux, city - *tower);
		}
		/*cout << "debug: " << aux << endl;*/
		if(ans < aux) ans = aux;
	}

	cout << ans << endl;
}
