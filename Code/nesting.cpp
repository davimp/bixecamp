#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 212;
string s, ans;
int tc;
int n;
int brac;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 1;
	cin >> tc;
	while(tc--){
		brac = 0;
		cin >> s;
		n = s.size();

		cout << "Case #" << cnt++ << ": ";
		fr(i, n){
			while(s[i]-'0' > brac){
				cout << '('; brac++;
			}

			while(s[i]-'0' < brac){
				cout << ')'; brac--;
			}

			cout << s[i];
		}
		while(brac--){
			cout << ")";
		}
		cout << endl;

	}
}
