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
const int MAX = 5123;

int n, q, l, r;
int sum[MAX];
int a[MAX];
pii p[MAX];
int aux, aux2, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	fr(i, q)
	{
		cin >> l >> r;
		p[i] = {l, r};
		for(int j = l; j <= r; j++)
		{
			a[j]++;
		}
	}

	ans = INT_MAX;

	fr(i, q)
	{
		aux = 0;
		l = p[i].f; r = p[i].s; sum[0] = 0;
		frr(j, n)
		{
			if(l <= j && j <= r) a[j]--;

			if(a[j] == 1) sum[j] = sum[j-1] + 1;
			else sum[j] = sum[j-1];

			if(a[j] == 0) aux++;
			
			if(l <= j && j <= r) a[j]++;
		}
		fr(j, q)
		{
			aux2 = aux + sum[p[j].s] - sum[p[j].f - 1];
			if(i != j && ans >= aux2) ans = aux2;
		}
	}

	cout << n - ans << endl;
}
