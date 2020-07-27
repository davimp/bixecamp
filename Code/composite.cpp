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
const int MAX = 2123;
const int N = 1000;
int lp[N+2];
vector<int> pr;

void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int tc;
int n;
int a[MAX];
int c[MAX];



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
    /*cout << pr.size() << endl;*/
    cin >> tc;
    while(tc--){
        cin >> n;
        fr(i, n){
            cin >> a[i];
            c[i] = 0;
        }

        int cnt, k, ok;
        k = 1; cnt = 0;
        for(int p : pr){
            ok = 0;
            fr(i, n)
                if(a[i]%p == 0 && c[i] == 0){c[i] = k; cnt ++; ok = 1;}
            if(cnt >= n) break;
            if(ok) k++;
        }

        cout << k << endl;
        fr(i, n){
            cout << c[i] << " ";
        }
        cout << endl;

    }
}
