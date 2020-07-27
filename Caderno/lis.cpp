#include<bits/stdc++.h>
using namespace std;

int n;
int lis()
{
  set<int> s;
  set<int>::iterator k;

  for(int i=0;i<n;i++)
  {
    if(s.insert(m[i]).second)
    {
      k = s.find(m[i]);
      k++;
      if(k != s.end()) s.erase(k);
    }
  }
  
  return s.size();

}
