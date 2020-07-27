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
int n, h, l, r;
int a[MAX];
int memo[MAX][MAX];

int pd(int i, int j){
	if(i == n && l <= j && j <= r) return 1;
	if(i == n) return 0;

	int& pdm = memo[i][j];
	if(pdm != -1) return pdm;

	if(l <= j && j <= r){
		if(i > 0) pdm = 1;
		else pdm = 0;
	}
	else{
		pdm = 0;
	}
	pdm += max(pd(i+1, (j+a[i]+h)%h), pd(i+1, (j+a[i]+h-1)%h));
	/*cout << "debug " << pdm << endl;*/
	return pdm;

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h >> l >> r;
	fr(i, MAX){
		fr(j, MAX){
			memo[i][j] = -1;
		}
	}

	fr(i, n)
		cin >> a[i];

	cout << pd(0, 0) << endl;
}
