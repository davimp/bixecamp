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
ll tc;
ll n, l, r;
ll index;

void solve(){
	index = 1;
	cin >> n >> l >> r;
	for(int i = 1; i < n; i++){
		if(l > 2*(n-i)){
			index += 2*(n-i);
			continue;
		}


	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		solve();
	}
}
