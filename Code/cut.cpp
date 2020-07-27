#include<bits/stdc++.h>
using namespace std;
const int MAX = 4007;
const int INF = 0x3f3f3f3f;
     
int n, a, b, c, memo[MAX][MAX];
     
int pd(int x, int len){
     
    if(len < 0) return -INF;
    if(len == 0) return x;
     
    int& pdm = memo[x][len];
    if(pdm != -1) return pdm;
     
    return pdm = max(max(pd(x + 1,len - a), pd(x + 1,len - b)), pd(x + 1,len - c));
        
}
     
int main(){
    cin >> n >> a >> b >> c;
    memset(memo, -1, sizeof(memo));
    cout << pd(0, n) << endl;
}