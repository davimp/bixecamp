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
const int MAX = 120;
int tc;
int n;
int m[MAX][MAX];
int k, r, c;
int num[MAX];
bool ok;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	int cnt;
	cnt = 1;
	while(tc--){
		k = c = r = 0;
		cin >> n;
		fr(i, n){
			ok = true;
			fr(j, n+2) num[j] = 0;
			fr(j, n){
				cin >> m[i][j];
				if(i == j) k += m[i][j];
				if(num[m[i][j]]){
					ok = false;
				}
				else{
					num[m[i][j]] = 1;
				}
			}
			if(!ok) r++;
		}


		fr(j, n){
			fr(i, n+2) num[i] = 0;
			ok = true;
			fr(i, n){
				if(num[m[i][j]]){
					ok = false;
				}
				else{
					num[m[i][j]] = 1;
				}
			}
			if(!ok){
				c++;
			}
		}


		cout << "Case #" << cnt++ << ": " << k  << " " << r << " " << c << endl;
	}
}
