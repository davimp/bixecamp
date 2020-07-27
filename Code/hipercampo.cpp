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
const int MAX = 11234;
int n, xa, xb;
pii a, b, aux;
int x, y;
map<pii, int> dp;
vector<pii> pontos;

int ori(pii p1, pii p2, pii p3) {
    
    int val = (p2.s - p1.s) * (p3.f - p2.f) -
              (p2.f - p1.f) * (p3.s - p2.s);

    return val;
}

/*ponto = {y, x}*/

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> xa >> xb;
    a = {0, xa};
    b = {0, xb};
    fr(i, n){
        cin >> x >> y;
        pontos.pb({y, x});
        dp[{y, x}] = 1;
    }

    sort(pontos.begin(), pontos.end());

    int ans;
    ans = 1;
    fr(i, n){
        int cnt = 0, sinal;
        aux = pontos[i];
        sinal = ori(b, a, aux);
        for(int j = i-1; j >= 0; j--){
            pii aux2;
            aux2 = pontos[j];
            if(ori(a, aux, aux2)*sinal >= 0 && ori(aux, b, aux2)*sinal >= 0){
                cnt = max(cnt, dp[aux2]);
            }
        }
        cnt++;
        dp[aux] = cnt;
        ans = max(ans, cnt);
    }

    cout << ans << endl;


}