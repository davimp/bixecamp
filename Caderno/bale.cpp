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

vector<ll> a;
ll n;

ll ic(vector<ll> &v){

	ll inv = 0;

	if (v.size() <= 1) return 0;

	vector<ll> u1, u2;


	for (ll i = 0; i < v.size()/2; i++)
		u1.push_back(v[i]);
	for (ll i = v.size()/2; i < v.size(); i++)
		u2.push_back(v[i]);
    
	inv += ic(u1);
	inv += ic(u2);


	u1.push_back(INT_MAX);
	u2.push_back(INT_MAX);

	ll ini1 = 0, ini2 = 0;
	for (ll i = 0; i < v.size(); i++){
		if (u1[ini1] <= u2[ini2])
			v[i] = u1[ini1++];
		else {
			v[i] = u2[ini2++];
			inv += u1.size() - ini1 - 1;
		}
	}


	return inv;
}

ll aux;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    fr(i, n)
    {
        cin >> aux;
        a.pb(aux);
    }

    cout << ic(a) << endl;
}
