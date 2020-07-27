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
int n, q, x, y;

int t[9][4*MAX], lz[4*MAX];

int a[MAX], aux, shift[10];

void build(int i, int l, int r) {
	if (l == r) {
		t[1][i] = 1;
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		fr(hiroshi, 9) t[hiroshi][i] = t[hiroshi][2*i] + t[hiroshi][2*i+1];
	}
}

void push(int i, int l, int r) {
	if (lz[i]) {
		int v = lz[i];
		lz[i] = 0;
		fr(h, 9) shift[h] = t[h][i]; 
		fr(h, 9)
		{
			t[(h+v)%9][i] = shift[h];
		}
		if (l != r) {
			lz[2*i] += v;
			lz[2*i+1] += v;
		}
	}
}

int query(int i, int j, int l, int r, int ql, int qr) {
	push(i, l, r);
	if (ql <= l && r <= qr) return t[j][i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, j, l, m, ql, qr) + query(2*i+1, j, m+1, r, ql, qr);
}

void update(int i, int l, int r, int ql, int qr, int x){
	push(i, l, r);
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		lz[i] += x;
		push(i, l, r);
	} else {
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		
		fr(hiroshi, 9) t[hiroshi][i] = t[hiroshi][2*i] + t[hiroshi][2*i+1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	/*cin >> n >> q;*/
	scanf("%d %d", &n, &q);

	build(1, 1, n);
	
	int w;
	int maior;
	while(q--)
	{
		scanf("%d %d", &x, &y);
		x++; y++;
		maior = -1; aux = 0;
		fr(j, 9)
		{
			w = query(1, j, 1, n, x, y);
			if(maior <= w){
				maior = w;
				aux = j;
			}
		}
		update(1, 1, n, x, y, aux);
	}


	fr(i, n)
	{
		maior = -1; aux = 0;
		fr(j, 9)
		{
			x = query(1, j, 1, n, i+1, i+1);
			if(maior <= x){
				maior = x;
				aux = j;
			}
		}
		a[i] = aux;
	}

	fr(i, n) printf("%d\n", a[i]);
		/*cout << a[i] << "\n";*/
	
	return 0;
}
