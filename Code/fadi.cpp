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
ll a, b, x;
ll a_, b_;
ll n;
int ok;
vector<ll> primes;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> x;
    a = 1;
    b = x;
    for(ll i = 2; i*i <= b; i++)
    {
        a = 1;
        ok = 0;
        while(b%i == 0)
        {
            a *= i;
            b /= i;
            ok = 1;
        }
        if(ok) primes.pb(a);
    }
    if(b > 1)
        primes.pb(b);
    a = b = 1;
    n = primes.size();
    a_ = b_ = 1e18;
    for(ll i = 0; i < (1 << n); i++)
    {
        a = b = 1;
        for(ll j = 0; j < n; j++)
        {
            if((i >> j) & 1) a*=primes[j];
            else b*=primes[j];
        }
        if(max(a, b) < max(a_, b_))
        {
            a_ = a;
            b_ = b;
        }
    }

    cout << b_ << " " << a_ << endl;

}
