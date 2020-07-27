#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
const int MAX = 1123;
int n, m;
int x, y, z;
int id[MAX];
int sz[MAX];
int a[MAX][MAX];
int u, v, d, a;
vector<tuple<int, int, int>> aresta;
vector<pii> ans;
 
int find(int p){
    if(id[p] == p) return p;
    return id[p] = find(id[p]);
}
 
void unio(int p, int q){
    p = find(p);
    q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q;
    sz[q] += sz[p];
}
 
 
void kruskal(vector<tuple<int, int, int>> ar){
    sort(ar.begin(), ar.end());
    fr(i, m){
        u = get<1>(ar[i]);
        v = get<2>(ar[i]);
        if(find(u) != find(v)){
            unio(u, v);
            if(v < u) swap(u, v);
            ans.pb(make_pair(u, v));
        }
    }
}
 
 
int main(){
    int cont = 1;

    cin >> n;

    cin >> d >> y;

    fr(i, n){
	sz[i] = 1;
	id[i] = i;
    }

    fr(i, n)
	    fr(j, n)
	    	cin >> a[i][j];

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){	
		if(a[i][j]) aresta.pb(make_tuple(1, i, j));
		else aresta.pb(make_tuple(y, i, j));
	}
    }

    fr(i, n)
	    fr(j, n)
	    	a[i][j] = 0;

    kruskal(aresta);
 
    for(auto x : ans){
        cout << x.f << " " << x.s << endl;
    }

    cout << endl;
    ans.clear();
    aresta.clear();
    cin >> n >> m;
}
 
