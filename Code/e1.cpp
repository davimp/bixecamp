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
int c[30][MAX];
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
		}
		frr(i, 26){
			ans = max(ans, c[i][n]);
		}

		frr(l, n){
			for(int r = l; r <= n; r++){
				big_out = big_in = 0;
				frr(w,26){
					if(big_in < c[w][r]-c[w][l-1]) big_in = c[w][r]-c[w][l-1];
					if(big_out < min(c[w][n] - c[w][r], c[w][l-1])) big_out = min(c[w][n] - c[w][r], c[w][l-1]);
				}
				/*cout << "debug: " << big_out << " " << big_in << endl;
				cout << l << " " << r << endl;*/
				if(ans < 2*big_out + big_in) ans = 2*big_out + big_in;
			}
		}
		cout << ans << endl;
	}
}
