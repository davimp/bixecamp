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
const int MAX = 11234;
int n;
int g[MAX], d[MAX], num[MAX];
vector<pair<double, int>> cow;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fr(i, n)
	{
		cin >> g[i] >> d[i];
		cow.pb({g[i], d[i]});
	}

	sort(cow.begin(), cow.end());
	int ans = 0;
	int k = 0;
	for(int i = n-1; i >= 0; i--){
		k = cow[i].s;

		while(k){
			if(!num[k]){
				num[k] = 1;
				ans += cow[i].f;
				break;
			}
			else{
				k--;
			}
		}
	}

	cout << ans << endl;


}
