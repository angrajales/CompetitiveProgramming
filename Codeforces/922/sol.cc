#include <bits/stdc++.h>

using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      int xr = j ^ i;
      if(xr <= n and xr > j and i + j > xr){ 
        //cerr << i << " " << j << " " << xr << endl;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}