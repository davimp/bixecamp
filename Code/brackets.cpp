#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define f first
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 1123456;

string s;
int a[4*MAX], b[4*MAX], c[4*MAX];
int hiroshi, n;
int aux, test, bb, cc;

void build(int i, int l, int r) {
	if (l == r) {
		if(s[l-1] == ')') c[i] = 1;
		else b[i] = 1;
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
	
		aux = min(b[2*i], c[2*i + 1]);
		aux = aux;
		a[i] = a[2*i] + a[2*i+1] + aux;
		b[i] = b[2*i] + b[2*i+1] - aux;
		c[i] = c[2*i] + c[2*i+1] - aux;
	}
}

tuple<int,int, int> query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr)
	{
		return {a[i], b[i], c[i]};
	}
	if (qr < l || r < ql)
	{ 
		return {0, 0, 0};
	}
	
	int m = (l+r)/2;
	int w;

	tuple<int, int, int> left, right;

	left = query(2*i, l, m, ql, qr);
	right = query(2*i+1, m+1, r, ql, qr);
	
	w = min(get<1>(left), get<2>(right));
	
	return {get<0>(left) + get<0>(right) + w, get<1>(left) + get<1>(right) - w, get<2>(left) + get<2>(right) - w};
}


int main()
{
	ios::sync_with_stdio(false);
	int x, y;
	cin >> s;
	n = s.size();

	build(1, 1, n);

	cin >> hiroshi;

	fr(i, hiroshi)
	{
		test = 0;
		cin >> x >> y;
		cout << 2*(get<0>(query(1, 1, n, x, y))) << "\n";
	}

}
