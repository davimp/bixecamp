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
ll n;
ll a[MAX], b[MAX];
ll memo[MAX][3];

ll pd(int i, int j){
    if(i >= n) return 0;

    ll &pdm = memo[i][j];
    if(pdm != -1) return pdm;

    if(!j){
        pdm = max(max(pd(i+1, 1) + a[i], pd(i+1, 2) + b[i]), pd(i+1, 0));
    }
    else if(j == 1){
        pdm = max(pd(i+1, 2) + b[i], pd(i+1, 0));
    }
    else{
        pdm = max(pd(i+1, 1) + a[i], pd(i+1, 0));
    }

    return pdm;
}

int main(){

    fr(i, MAX){
        fr(j, 3){
            memo[i][j] = -1;
        }
    }
    
    cin >> n;

    fr(i, n){
        cin >> a[i];
    }

    fr(i, n){
        cin >> b[i];
    }

    cout << pd(0, 0) << endl;

}
