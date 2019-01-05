#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int mn = min(a, b);
  int mx = max(a, b);
  int res = (mx - mn) * (mx - mn + 1) / 2; 
  for(int i = mn; i <= mx; ++i){
    int s1 = (mx - i) * (mx - i + 1) / 2;
    int s2 = (i - mn) * (i - mn + 1) / 2;
    res = min(res, s1 + s2);
  }
  cout << res << endl;
  return 0;
}