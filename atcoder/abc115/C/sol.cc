#include <bits/stdc++.h>

using namespace std;

int a[100002];

int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int res = 1000000001;
  for(int i = 0; i < n - k + 1; ++i){
    res = min(res, a[k + i - 1] - a[i]);
  }
  cout << res << endl;
  return 0;
}