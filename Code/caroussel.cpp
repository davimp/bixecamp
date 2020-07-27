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
const int MAX = 212345;
int tc;
int n;
int a[MAX];
int k;
int c[MAX];
int p[3];
int aux;
int ok;
int par;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    p[0] = 1;
    p[1] = 2;
	cin >> tc;
    while(tc--){
        aux = 0; k = 1;
        cin >> n;
        ok = 1;
        par = -1;
        fr(i, n){
            cin >> a[i];
            if(i > 0 && a[i] != a[i-1]) ok = 0;
            if(i > 0 && a[i] == a[i-1]) par = i;
            c[i] = 1;
        }
        if(a[n-1] == a[0]) par = n;

        if(n%2 == 0 && !ok){
            k = 2;
            fr(i, n){
                c[i] = i%2 + 1;
            }
        }
        else if(!ok){
            if(par != -1){
                k = 2;
                fr(i, n){
                    if(i != par) aux = (aux+1)%2;
                    c[i] = p[aux];
                }
                if(par == n) c[n-1] = c[0];
            }
            else{
                k = 3;
                fr(i, n){
                    c[i] = i%2 + 1;
                }
                c[n-1] = 3;
            }
        }
        cout << k << endl;
        fr(i, n) cout << c[i] << " ";
        cout << endl;
    }
}
