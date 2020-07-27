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
int tc;
int n, l, r;
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		cin >> n >> l >> r;
		int x, cnt1, cnt2, aux;
		cnt1 = 1;
		cnt2 = 2;
		x = n-1;
		aux = r-l+1;
		while(l - 2*x > 0){
			cnt1++;
			l -= 2*x;
			x--;
		}

		cnt2 = cnt1+l;
		while(aux > 0){
			if(cnt2 > n){
				
				cnt1++;
				cnt2 = cnt1 + 1;
			}
			if(aux) ans.pb(cnt1);
			if(aux > 1) ans.pb(cnt2);
			cnt2++;

			aux -= 2;
		}
		for(auto le : ans)
			cout << le << " ";
		cout << endl;
	}
}
