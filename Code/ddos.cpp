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
const int MAX = 5123;
int n;
int r[MAX];
int aux;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	frr(i, n){
		cin >> aux;
		r[i] = aux + r[i-1];
	}
	int ans;
	ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(r[j] - r[i-1] > 100*(j-i+1)){
				if(j-i+1 > ans) ans = j-i+1;
			}
		}
	}

	cout << ans << endl;
}
