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
const int MAX = 212345;
int n, m, q;
int x, y;
int id[MAX];
int sz[MAX];
int a[MAX];
 
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
    cin >> n;

    frr(i, n)
    {
	    sz[i] = 1; id[i] = i;
    }
/*    sz[n] = n;*/

    frr(i, n)
    {
	    cin >> a[i];
    }
    cin >> q;
    frr(i, q)
    {
        frr(i, n)
	{
	    cin >> x;
	    if(find(x) != i)
		    unio(x, i);
	}
	  
    }


    cin >> x;
    frr(i, n)
	    if(x == a[i])
	    {
		    y = i; break;
	    }


    if(find(1) == find(y))
	    cout << "YES" << endl;
    else
	    cout << "NO" << endl;
}
