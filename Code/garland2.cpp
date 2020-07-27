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
const int MAX = 112;
int n;
int a[MAX], first;
int uns, zeros;
int cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	zeros = n/2;
	uns = n -  zeros;
	first = -1;
	cnt = 0;
	
	fr(i, n)
	{
		cin >> a[i];
		if(a[i] != 0)
		{
			a[i] = a[i]%2;
			if(first == -1) first = a[i];
			if(a[i])
				uns--;
			else
				zeros--;
		}
		else
			a[i] = -1;
	}
	
	if(a[0] == -1)
	{
		if(first)
		{
			if(uns) {a[0] = 1; uns--;}
			else {a[0] = 0; zeros--;}
		}
		else
		{
			if(zeros) {a[0] = 0; zeros--;}
			else {a[0] = 1; uns--;}
		}	
	}

	frr(i, n-1)
	{
		if(a[i] == -1)
		{
			if(a[i-1])
			{
				if(uns) {a[i] = 1; uns--;}
				else {a[i] = 0; zeros--;}
			}
			else
			{
				if(zeros) {a[i] = 0; zeros--;}
				else {a[i] = 1; uns--;}
			}
		}
	}

	frr(i, n-1)
	{
		if(a[i] != a[i-1]) cnt++;
	}

	cout << cnt << endl;
}
