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
ll n, m, p;
ll x, y;
ll a[MAX], b[MAX];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p;

	for(ll i = 0; i < n ;i++){
		cin >> a[i];
		if(a[i]%p != 0){
			x = i;
		}
	}

	for(ll i = 0; i < m; i++){
		cin >> b[i];
		if(b[i]%p != 0){
			y = i;
		}
	}

	n = x + y;

	cout << x+y << endl;

}
