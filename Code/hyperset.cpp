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
const int MAX = 1512;
int n, k;
char cards[MAX][40];
map<string,  int> a;
char c[40];
int cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cnt = 0;
	fr(i, n){
		cin >> cards[i];
		a[cards[i]] = i;
	}


	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int w = 0; w < k; w++){
				if(cards[j][w] == cards[i][w]){
					c[w] = cards[i][w];
				}
				else{
					c[w] = 'S'+'E'+'T' - cards[i][w] - cards[j][w];
				}
			}
			c[k] = '\0';

			if(a.count(c) && a[c] > j) cnt++;
		}
	}



	cout << cnt << endl;
}
