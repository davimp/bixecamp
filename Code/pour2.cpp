#include<bits/stdc++.h>
using namespace std;

int t, a, b, c, d, e, f;
int steps;

int gcd(int i, int j)
{
	if(j == 0) return i;
	else return gcd(j, i%j);
}

int main()
{
	cin >> t;
	while(t--)
	{
		steps = 0;
		cin >> a >> b >> c;
		if(a<b) swap(a, b);
		d = gcd(a, b);
		if((c%d == 0) && (c <= a))
		{
			
		}
		else
			steps = -1;
		cout << steps << endl;
	}
}
