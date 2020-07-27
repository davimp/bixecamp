#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 5123;
string s, t;
int tams, tamt;
int memo[MAX][MAX];

int pd(int a, int b){
    if(a == tams || b == tamt) return 0;
    if(a > tams || b > tamt) return INT_MIN;

    int &pdm = memo[a][b];
    if(pdm != -1) return pdm;

    if(s[a] == )
}

int main(){
    fr(i, MAX)
        fr(j, MAX)
            memo[i][j] = -1;
    
    cin >> s;
    cin >> t;

    tams = s.length();
    tamt = t.length();

    cout << pd(0 , 0) << endl;
    
}
