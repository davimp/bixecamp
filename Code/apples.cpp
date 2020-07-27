#include<bits/stdc++.h>
using namespace std;
const int MAX = 107;
const int INF = 0x3f3f3f3f;
int c, n, k, ans;
int memo[MAX][MAX], cost[MAX];
     
int pd(int ap, int pac, int id){
     
    if(ap == k) return 0;
    if((id > k)||(pac <= 0)||(ap > k)) return INF;
        
    int& pdm = memo[ap][pac];
    if(pdm != -1) return pdm;
    if(cost[id] == -1) return pdm = pd(ap, pac, id + 1);
     
    return pdm = min(min(pd(ap + id, pac - 1, id + 1) + cost[id], pd(ap + id, pac - 1, id) + cost[id]), pd(ap, pac, id + 1));
}
     
int main(){
    cin >> c;
    while(c--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> cost[i];
        } 
        memset(memo, -1, sizeof(memo));
     
        ans = pd(0, n , 1);
     
        if(ans == INF){
            ans = -1;
        }    
        cout << ans << endl;
    }    
    return 0;
} 