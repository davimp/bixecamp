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
vector<int> a;
int n;


int solve(vector<int> v, int bit){
	if(v.size() == 0 || bit < 0) return 0;

	vector<int> um, zero;
	for(auto i : v){
		if((i >> bit)&1) um.pb(i);
		else zero.pb(i);
	}

	if(um.empty()) return solve(zero, bit-1);
	if(zero.empty()) return solve(um, bit-1);

	return min(solve(zero, bit-1), solve(um, bit-1)) + (1 << bit);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a)
		cin >> i;

	cout << solve(a, 30) << endl;
}
