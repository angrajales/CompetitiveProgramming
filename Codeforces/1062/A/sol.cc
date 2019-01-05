#include <bits/stdc++.h>

using namespace std;

int a[1001];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n ; ++i) cin >> a[i];
  int res = 0;
  int cur = a[0];
  int cnt = 0;
  for(int i = 1; i < n - 1; ++i){
    if(cur + 1 == a[i]){
      cnt++;
    }else{
      cnt = 0;
    }
    res = max(res, cnt - 1);
    cur = a[i];
  }
  cout << res << endl;
  return 0;
}