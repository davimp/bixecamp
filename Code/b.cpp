#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define f first
#define s second
#define fr(i, n) for(ll i = 0; i < n; i++)
#define frr(i, n) for(ll i = 1; i<= n; i++)
#define MOD 1000000007
const ll MAX = 112345;
ll n, l;
ll anterior, proximo;
ll ok, ma, me;
vector<ll> maior, menor;
ll err;

int main()
{
	err = 0;
	cin >> n;
	fr(i, n)
	{
		cin >> l;
		ok = 0;
		fr(j,l)
		{
			if(j==0){ cin >> anterior; ma = anterior; me = anterior;}
			else
			{
				cin >> proximo;
				if(anterior < proximo)
					ok = 1;
				if(proximo < me) me = proximo;
				if(proximo > ma) ma  = proximo;
				anterior = proximo;
			}
		}
		if(!ok || l == 1)
		{
			/*cout << i << endl;*/
			maior.pb(ma);
			menor.pb(me);
		}
	}
	sort(maior.begin(), maior.end());
	for(auto x : menor)
		err += upper_bound(maior.begin(), maior.end(), x) - maior.begin();
		
	cout << n*n - err << endl;
}
