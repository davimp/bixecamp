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
set<int> fila;

int main(){
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		fr(i, n)
		{
			int aux;
			cin >> aux;
			fila.insert(aux);
		}
		cout << fila.size() << "\n";
		fila.clear();
	}
}
