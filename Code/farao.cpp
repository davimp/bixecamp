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
const int INF = 0x3f3f3f3f;
int n, q;
int a[MAX];
int x, y;

typedef struct no{
	pii t;
	pii pre;
	pii su;
	pii tot;
} Node;

Node str[4*MAX];

void build(int i, int l, int r) {
	if (l == r){
		str[i].t.f = str[i].pre.f = str[i].su.f = str[i].tot.f = a[l];
		str[i].t.s = str[i].pre.s = str[i].su.s = str[i].tot.s = 1;
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);

		/*atualiza prefixo*/
		if(str[2*i].pre.f < str[2*i+1].pre.f + str[2*i].tot.f){
			str[i].pre.f = str[2*i+1].pre.f + str[2*i].tot.f;
			str[i].pre.s = str[2*i+1].pre.s + str[2*i].tot.s;
		}
		else if(str[2*i].pre.f == str[2*i+1].pre.f + str[2*i].tot.f && str[2*i].pre.s < str[2*i+1].pre.s + str[2*i].tot.s)
		{
			str[i].pre.f = str[2*i+1].pre.f + str[2*i].tot.f;
			str[i].pre.s = str[2*i+1].pre.s + str[2*i].tot.s;
		}
		else
		{
			
			str[i].pre = str[2*i].pre;
		}
		
		
		/*atualiza sufixo*/
		if(str[2*i+1].su.f < str[2*i].su.f + str[2*i+1].tot.f){
			str[i].su.f = str[2*i].su.f + str[2*i+1].tot.f;
			str[i].su.s = str[2*i].su.s + str[2*i+1].tot.s;
		}
		else if(str[2*i+1].su.f == str[2*i].su.f + str[2*i+1].tot.f && str[2*i+1].su.s < str[2*i].su.s + str[2*i+1].tot.s){
			str[i].su.f = str[2*i].su.f + str[2*i+1].tot.f;
			str[i].su.s = str[2*i].su.s + str[2*i+1].tot.s;
		}
		else
		{
			str[i].su = str[2*i+1].su;
		}

		/*autaliza total*/
		str[i].tot.f = str[2*i].tot.f + str[2*i+1].tot.f; 
		str[i].tot.s = str[2*i].tot.s + str[2*i+1].tot.s; 

		/*atualiza a seg*/
		if(str[2*i].t <= str[2*i+1].t) str[i].t = str[2*i+1].t;
		else str[i].t = str[2*i].t;

		if(str[i].t < str[i].pre) str[i].t = str[i].pre;
		if(str[i].t < str[i].su) str[i].t = str[i].su;

		pii teste;
		teste.f = str[2*i].su.f + str[2*i+1].pre.f;
		teste.s = str[2*i].su.s + str[2*i+1].pre.s;

		if(str[i].t < teste) str[i].t = teste;
	}
}

Node query(int i, int l, int r, int ql, int qr) {
	Node ans;
	if (ql <= l && r <= qr) return str[i];
	if (qr < l || r < ql){
		ans.t.f = ans.t.s = ans.pre.f = ans.pre.s = ans.su.f = ans.su.s = ans.tot.f = ans.tot.s = 1;
		ans.t.f = -INF;
		return ans;
	}
	int m = (l+r)/2;
	Node le;
	Node ri;
	le = query(2*i, l, m, ql, qr);
	ri = query(2*i+1, m+1, r, ql, qr);
	
	if(le.t.f == -INF)
			return ri;
	if(ri.t.f == -INF)
			return le;
	/*atualiza prefixo*/
		if(le.pre.f <= ri.pre.f + le.tot.f){
			ans.pre.f = ri.pre.f + le.tot.f;
			ans.pre.s = ri.pre.s + le.tot.s;
		}
		else if(le.pre.f == ri.pre.f + le.tot.f && le.pre.s < ri.pre.s + le.tot.s){
			ans.pre.f = ri.pre.f + le.tot.f;
			ans.pre.s = ri.pre.s + le.tot.s;
		}
		else
		{
			ans.pre = le.pre;
		}
		
		/*atualiza sufixo*/
		if(ri.su.f <= le.su.f + ri.tot.f){
			ans.su.f = le.su.f + ri.tot.f;
			ans.su.s = le.su.s + ri.tot.s;
		}
		else if(ri.su.f == le.su.f + ri.tot.f && ri.su.s < le.su.s + ri.tot.s){
			ans.su.f = le.su.f + ri.tot.f;
			ans.su.s = le.su.s + ri.tot.s;
		}
		else
		{
			ans.su = ri.su;
		}

		/*autaliza total*/
		ans.tot.f = le.tot.f + ri.tot.f; 
		ans.tot.s = le.tot.s + ri.tot.s; 

		/*atualiza a maior sequencia*/
		if(le.t < ri.t) ans.t = ri.t;
		else ans.t = le.t;

		if(ans.t < ans.pre) ans.t = ans.pre;
		if(ans.t < ans.su) ans.t = ans.su;

		pii teste;
		teste.f = le.su.f + ri.pre.f;
		teste.s = le.su.s + ri.pre.s;

		if(ans.t < teste) ans.t = teste;

		return ans;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		frr(i, n)
		{
			cin >> a[i];
		}
		build(1, 1, n);
		cin >> q;
		fr(i, q)
		{
			Node aux;
			cin >> x >> y;
			aux = query(1, 1, n, x, y);
			cout << aux.t.f << " " << aux.t.s << endl;
		}
	
	}
}
