#include <bits/stdc++.h>

using namespace std;

int a[1003];

int main(){
  int n, l;
  cin >> n >> l;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  a[0] = 0;
  a[n + 1] = l;
  sort(a, a + (n + 1));
  double res = 0.0;
  for(int i = 1; i <= n; ++i){
    res = max(res, (a[i] - a[i - 1]) / 2.0);
    res = max(res, (a[i + 1] - a[i]) / 2.0);
  }
  res = max(res, 1.0 * (a[1] - a[0]));
  res = max(res, 1.0 * (a[n + 1] - a[n]));
  printf("%.11f", res);
  return 0;
}