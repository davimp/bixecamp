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
ll n, m;
ll a[MAX];
ll dp[MAX];
ll sum;
     
int main(){
    cin >> n >> m;
    fr(i, n){
        cin >> a[i];
    }
    sort(a, a + n);
     
    sum = 0;
    int aux;
    fr(i, n){
        aux = i%m;
        dp[aux] += a[i];
        sum += dp[aux];
        cout << sum << " ";
    }
    cout << endl;         
}