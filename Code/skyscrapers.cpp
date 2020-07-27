#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define f first
#define s second
#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i<= n; i++)
#define MOD 1000000007
const ll MAX = 2123;
ll n;
ll m[MAX];
set<pll> fila;
ll l, r;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fr(i, n){
		cin >> m[i];
	}
	l = 0; r = n-1;
	while(r > l){
		ll minimo, index, left, right;
		minimo = INT_MAX;
		left= right = 0;
		for(ll i = l; i <= r; i++){
			if(minimo >m[i]){
				minimo = m[i];
				index = i;
			}
		}
		/* left  */
		for(ll i = index-1; i >= l; i--){
			left += m[i]- minimo;
		}
		/* right */
		for(ll i = index+1; i <= r; i++){
			right += m[i]- minimo;
		}
		if(left < right){
			for(ll i = index-1; i >= l; i--){
				m[i]= minimo;
			}
			l = index+1;
		}
		else{
			for(ll i = index+1; i <= r; i++){
				m[i]= minimo;
			}
			r = index-1;
		}
	}
	fr(i, n){
		cout << m[i] << " ";
	}
	cout << "\n";
}
