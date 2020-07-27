#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 2123;
int tc;
string s;
string sufix, prefix;
string best;
int ans;
int k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		ans = 0;
		int n;
		cin >> n;
		cin >> s;

		ans = 1; best = s;
		for(k = 1; k <= n; k++){
			sufix = s.substr(0, k-1);
			prefix = s.substr(k-1, n-k+1);
			if(n%2 == k%2)
				reverse(sufix.begin(),sufix.end());
			if(prefix+sufix < best){
				best = prefix+sufix;
				ans = k;
			}
		}

		cout << best << "\n";
		cout << ans << "\n";


	}
}
