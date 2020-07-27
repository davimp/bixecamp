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
int tc, n;
int a;
int par, impar;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		par = impar = 0;
		cin >> n;
		fr(i, n){
			cin >> a;
			if(a%2){
				impar++;
			}
			else{
				par++;
			}
		}

		if(n%2){
			if(impar) cout << "YES" << endl;
			else  cout << "NO" << endl;
		}
		else{
			if(par && impar) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
