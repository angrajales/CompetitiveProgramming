#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  string s1, s2;
  int res = 0;
  if(a.size() > b.size()){
    s1 = b;
    res = a.size() - b.size();
    s2 = a.substr(res);
  }
  else if(b.size() > a.size()){
    s1 = a;
    res = b.size() - a.size();
    s2 = b.substr(res);
  }else{
    s1=a;
    s2=b;
  }
  int last = 0;
  for(int i = 0; i < s1.size(); i++){
    if(s1[i] != s2[i]) last = i+1;
  }
  res += (2*last);
  cout<< res <<endl;
}