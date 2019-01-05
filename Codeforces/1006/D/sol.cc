#include <bits/stdc++.h>

using namespace std;
  
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string a, b;
  cin >> n >> a >> b;
  int cost = 0, res = 0;
  for(int i = 0; i < a.size(); ++i){
    if(a[i] != b[i]){
      if(a[n - i - 1] != b[n - i - 1]){
        if(a[i] != a[n - i - 1]){
          char prev1 = a[i];
          a[i] = a[n - i - 1];
          a[n - i - 1] = prev1;
          if(a[i] == b[i]){
            if(a[n - i - 1] == b[n - i - 1]){
              continue;
            }
          }else{
            res += 1;
            a[i] = b[i];
            continue;
          }
        }else{
          res += 1; 
        }
      }
    }else{
      cost = 0;
    }
    res += cost;
  }
  cout << res << endl;
  return 0;
}