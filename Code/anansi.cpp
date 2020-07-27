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
const int MAX = 112345;
int n, m, q;
int x, y, z;
int id[MAX];
int sz[MAX];
int u, v, cnt;

vector<pair<int, int>> aresta;
stack<int> ans;
vector<int> cut, cut2;
 
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
 
 
int main(){
    cut2.clear(); cut.clear();
    int cont = 1;
    cin >> n >> m;
    fr(i, n){
    	sz[i] = 1;
    }
    cnt = n;

    fr(i, m){
        cin >> x >> y;
        aresta.pb(make_pair(x, y));
      	id[x] = x;
        id[y] = y;
    }
    cin >> q;
    fr(i, q){
	cin >> z;
	z--;
	cut2.pb(z);
	cut.pb(z);
    }
    sort(cut2.begin(), cut2.end());
    int j = 0;
    fr(i, m){
	if(i == cut2[j]){
		j++;
	}
	else{
		if(find(aresta[i].f) != find(aresta[i].s))
		{
			unio(aresta[i].f, aresta[i].s); cnt--;
		}
	}
    }
    fr(i, q){
    	ans.push(cnt);
	int x = cut[q-1-i];
	if(find(aresta[x].f) != find(aresta[x].s))
	{
		unio(aresta[x].f, aresta[x].s); cnt--;
	}
    }

    while(!ans.empty())
    {
    	cout << ans.top() << " ";
	ans.pop();
    }

    cout << endl;
}
