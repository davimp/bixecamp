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
const int MAX = 212345;
int n;
vector<pii> p;
multiset<int> a;
int aux, cnt, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans = 0;
	cin >> n;
	fr(i, n){
		cin >> aux;
		p.pb({aux, 0});
	}
	fr(i, n){
		cin >> aux;
		p[i].s = aux;
	}
	int sum, num;
	sort(p.begin(), p.end());
	for(auto x : p) cout << x.f << " ";
	cout << "\n";
	sum = 0;
	int dif;
	dif = 0;
	fr(i, n-1){
		if(i > 0) dif = p[i].f - p[i-1].f;
		while(!a.empty() && (dif--) > 1){
			sum -= *a.rbegin();
			a.erase(*a.rbegin());
			ans += sum;
		}

		if(p[i].f == p[i+1].f){
			sum += p[i].s;
			a.insert(p[i].s);
		}
		
		ans += sum;
	}
	
	/*while(!a.empty()){
		ans += sum;
		sum -= *a.rbegin();
		a.erase(*a.rbegin());
	}*/

	cout << ans << endl;
}
