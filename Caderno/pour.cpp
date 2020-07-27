#include<bits/stdc++.h>
using namespace std;
 
int steps;
 
int mdc(int a, int b){
  if((a%b)==0) return b;
  else return mdc(b, a%b);
}
 
int pour (int a, int b, int c, int x, int y){
  if((x==c)||(y==c)){
    return steps;
  }
  else if(x==0){
    x = a; steps ++;
    return pour(a, b, c, x, y);
  }
  else if(y==b){
    y = 0; steps ++;
    return pour(a, b, c, x, y);
  }
  else{
    int z;
    z = b - y;
    if(z >= x){
      y = y + x;
      x = 0;
      steps ++;
      return pour(a, b, c, x, y);
    }
    else{
      x = x - z;
      y = b;
        steps ++;
      return pour(a, b, c, x, y);
    }
  }
}
 
 
int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    steps = 0;
    int a, b ,c, d, e, f;
    cin >> a >> b >> c;
    d = mdc(a, b);
    if(a<b) swap(a, b);
    if(((c%d)==0)&&(c<=a)){
      e = pour(a, b, c, 0, 0);
      steps = 0;
      f = pour(b, a, c, 0, 0);
      if(e > f) steps = f;
      else steps = e;
    }
    else{
      steps = -1;
    }
    cout << steps << endl;
  }
}
