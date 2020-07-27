#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
int a[MAXN];
int n;

long long search(int p){
    long long sum = 0;
    
    /* right */
    int now = a[p];
    for(int i = p+1 ; i < n ; i++){
        if(a[i] > now) sum += now;
        else{
            now = a[i];
            sum += now;
        }
    }
    /* left */
    now = a[p];
    for(int i = p ; i >= 0 ; i--){
        if(a[i] > now) sum += now;
        else{
            now = a[i];
            sum += now;
        }
    }
    return sum;
}
int main(){
    int p = 0;
    ios::sync_with_stdio(0);
    long long sum = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        long long temp = search(i);
        if(sum < temp){
            sum = temp;
            p = i;
        }
    }
    int now = a[p];
    for(int i = p+1 ; i < n ; i++){
        if(a[i] > now) a[i] = now;
        else now = a[i];
    }
    now = a[p];
    for(int i = p-1 ; i >= 0 ; i--){
        if(a[i] > now) a[i] = now;
        else now = a[i];
    }
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
}