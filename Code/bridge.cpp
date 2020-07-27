#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 112345;
ll tc, n, a, b;
vector<pll> p;
ll m[MAX];

ll lis()
{
  set<ll> s;
  set<ll>::iterator k;

  for(ll i=0;i<n;i++)
  {
    if(s.insert(m[i]).second)
    {
      k = s.find(m[i]);
      k++;
      if(k != s.end()) s.erase(k);
    }
  }
  return s.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		cin >> n;
		fr(i, n){
			cin >> a;
			p.pb({a, 0});
		}
		fr(i, n){
			cin >> b;
			p[i].second = b;
		}
		sort(p.begin(), p.end());
		fr(i, n){
			m[i] = p[i].second;
		}

		cout << lis() << endl;
		p.clear();
	}
}
