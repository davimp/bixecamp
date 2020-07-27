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
vector<pair<pii, int>> a;
int n, x, y;
int tc;
int fc, fj;
char ta[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	int cnt;
	cnt = 1;
	while(tc--){
		bool ok = true;
		cin >> n;
		fr(i, n){
			cin >> x >> y;
			a.pb({{x, y}, i});
		}
		sort(a.begin(), a.end());
		fj = 0;
		fc = 0;
		fr(i, n){
			if(a[i].f.f >= fj){
				fj = a[i].f.s;
				ta[a[i].s] = 'J';
			}
			else if(a[i].f.f >= fc){
				fc = a[i].f.s;
				ta[a[i].s] = 'C';
			}
			else{
				ok = false;
				break;
			}
		}

		/* fim */
		if(ok){
			cout << "Case #" << cnt++ << ": ";
			fr(i, n){
				cout << ta[i];
			}
			cout << endl;
		}
		else
		{
			cout << "Case #" << cnt++ << ": IMPOSSIBLE" << endl;
		}

		a.clear();
	}
}
