#include <bits/stdc++.h>

using namespace std;

int a[(1<<20) + 10];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= m + 1; ++i) cin >> a[i];
  int fedor = a[m + 1];
  int res = 0;
  for(int i = 1; i <= m; ++i){
    int kp = 0;
    for(int j = 0; j < 31; ++j){
      if((fedor & (1 << j)) != (a[i] & (1 << j))){
        kp++;
      }
    }
    if(kp <= k){
      res++;
    }
  }
  cout << res << endl;
  return 0;
}