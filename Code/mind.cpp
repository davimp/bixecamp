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
const int MAX = 3512;
int t;
int n, m, k;
int aux, aux2;
int ans, ansp;
int a[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		ans = INT_MIN;
		cin >> n >> m >> k;
		fr(i, n)
			cin >> a[i];
		
		k = min(k, m - 1);
		fr(i, k + 1)
		{
			ansp = max(a[i], a[n-m+i]);
			fr(j, m - k)
			{
				aux = i + j;
				ansp = min(ansp, max(a[aux], a[n - m + aux]));
			}
			ans = max(ans, ansp);		
		}

		cout << ans << endl;
	}
}
