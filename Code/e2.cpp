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
int c[200][MAX];
int pos[200][MAX];
int tc;
int a, n;
int ans, cnt, big_out, big_in;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		ans = 0;
		cin >> n;
		frr(i, n){
			cin >> a;
			fr(j, 27){
				c[j][i] = c[j][i-1];
			}
			c[a][i]++;
			pos[a][c[a][i]] = i;
		}
		frr(i, 26){
			ans = max(ans, c[i][n]);
		}
		big_out = big_in = 0;
		frr(i, 26){
			for(int k = 1; k <= c[i][n]/2; k++){
				int l, r;
				l = pos[i][k];
				r = pos[i][c[i][n] - k];
				big_in = 0;
				fr(j, 26){
					if(big_in < c[j][r] - c[j][n]) big_in < c[j][r] - c[j][n];
				}
				if(ans < 2*k + big_in) ans = 2*k + big_in;
			}
		}

		cout << ans << endl;
	}
}
