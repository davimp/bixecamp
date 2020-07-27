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
const int MAX = 312345;
ll tc, n;
ll a[MAX], b[MAX];
vector<pii> p;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		ll j, small;
		cin >> n;
		fr(i, n){
			cin >> a[i] >> b[i];
		}
		small = 1e13;
		j = 0;
		fr(i, n){
			ll dif;
			dif = a[(i+1)%n];
			if(0 < a[(i+1)%n] - b[i]) dif -= a[(i+1)%n] - b[i];
			if(dif <= small){
				small = dif;
				j = i;
			}
		}
		b[j] = 0;
		ll ans, cnt, i;
		ans = 0;
		cnt = n;
		i = (j+1)%n;
		while(cnt--){
			if(a[i] - b[(i-1 < 0?n-1:i-1)] > 0) ans += a[i] - b[(i-1 < 0?n-1:i-1)];
			i = (i+1)%n;
		}

		cout << ans << endl;
	}
}
