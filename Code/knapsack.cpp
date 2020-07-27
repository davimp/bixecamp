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
int memo[MAX][MAX];
int s, n;
int a, b;
vector<pii> pac;


int dp(int i, int total){
    if(total > s) return INT_MIN;
    if(i == n) return 0;

    int& pdm = memo[i][total];
    if(pdm != -1) return pdm;


    return pdm = max(dp(i+1, total), dp(i+1, total + pac[i].f) + pac[i].s);
}

int main(){
    fr(i, MAX){
        fr(j, MAX){
            memo[i][j] = -1;
        }
    }

    cin >> s >> n;
    fr(i, n){
        cin >> a >> b;
        pac.pb({a, b}); 
    }

    cout << dp(0, 0) << endl;
}
