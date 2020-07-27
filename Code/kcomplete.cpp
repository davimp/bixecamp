#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 212345;
int tc;
int n, k;
int x, y, z;
int id[MAX];
int sz[MAX];
char aux[MAX];
int u, v;
int f[MAX][30];
set<int> c;
string s;

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
    while(tc--){
        cin >> n >> k;
        cin >> s;
        fr(i, n){
            fr(j, 30)
                f[i][j] = 0;
        }
        fr(i, n){
            sz[i] = 1;
            id[i] = i;
        }
        fr(i, n){
            unio(i, (i+k >= n? i:i+k));
            unio(i, n-i-1);
        }
        
        fr(i, n){
            c.insert(find(i));
            f[find(i)][s[i]-'a']++;
        }

        int cnt;
        cnt = 0;
        for(int x : c){
            int m;
            m = 0;
            fr(i, 27){
                if(m < f[x][i]) m = f[x][i];
            }

            cnt += sz[x] - m;
        }

        cout << cnt << endl;
        c.clear();
    }
}
