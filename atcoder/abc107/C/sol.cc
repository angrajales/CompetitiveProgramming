#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int a[N];

int main(){
  int n, k;
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int res = 0;
  a[0] = 0;
  a[n + 1] = 1001;
  for(int i = 0; i <= n; ++i){
    for(int j = i + 1; j <= n + 1; ++j){
      if(a[j] - j == a[i] - i){
        res = max(res, j - i - 1);
      }
    }
  }
  cout << res << endl;
  return 0;
}