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
const int MAX = 112345;
ll t;
ll n, m, a[MAX];
ll pot[MAX];
ll sum;
int ans;
ll limit;
int aux, cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		sum = 0; ans = 0;
		cin >> n >> m;
		fr(i, MAX) pot[i] = 0;
		fr(i, m)
		{
			cnt = 0;
			cin >> a[i]; sum += a[i];
			
			aux = a[i];
			while(aux/2 != 0)
				{cnt++; aux/=2;}
			pot[cnt]++;
			
		}
		if(sum < n)
		{
			cout << -1 << endl;
		}
		else
		{
			ans = 0;
			limit = (ll)log2(n) + 1;
			for(ll i = 0; i < limit && n; i++)
			{
				if(n&1)
				{
					if(!pot[i])
					{

						int k;
						k = i + 1;
						while(!pot[k])
						{
							k++;
						}

						while(k > i)
						{
							pot[k]--;
							pot[k-1] += 2;
							ans++; k--;
						}
					}
					pot[i]--;
				}
				pot[i+1] += pot[i]/2;
				n = (n >> 1);
			}
			cout << ans << endl;
		}
	}
}
