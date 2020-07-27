#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i<= n; i++)
#define MOD 1000000007
const int MAX = 2123456;
int tc;
string s;
string a, b;
string t;
string str;
int pref[MAX];
int c;

string pre_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while(tc--){
		int n, ans, k;
		ans = 0;
		cin >> s;
		n = (int)s.size();
		k = 0;
		/*fr(i, n+1) pref[i] = 0;*/
		while(k < n-1-k && s[k] == s[n-1-k]) k++;
		if(k){
			cout << s.substr(0, k);
		}
		if(n > 2*k){
			string t, b, a;
			t = s.substr(k, n - 2*k);
			a = pre_palindrome(t);
			reverse(t.begin(), t.end());
			b = pre_palindrome(t);
			if(a.size() >= b.size())
				cout << a;
			else
				cout << b;
		}
		if(k){
			cout << s.substr(n-k, k);
		}

		cout << "\n";
	}
}
