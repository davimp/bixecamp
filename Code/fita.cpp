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
const int MAX = 11234;
int a[MAX];
int n;
int aux;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fr(i, n)
	{
		cin >> a[i];
		if(a[i] == -1)
		{
			a[i] = 10000;
		}
	}
	aux = 1000;
	fr(i, n)
	{
		if(a[i])
		{
			aux++; aux = min(aux, 9);
			a[i] = min(a[i], aux);
		}
		else
		{
			aux = 0;
		}
	}
	
	aux = 1000;
	for(int i = n-1; i >= 0; i--)
	{
		if(a[i])
		{
			aux++; aux = min(aux, 9);
			a[i] = min(a[i], aux);
		}
		else
		{
			aux = 0;
		}
	}
		
	fr(i, n)
		cout << a[i] << " ";
	cout << endl;
}
