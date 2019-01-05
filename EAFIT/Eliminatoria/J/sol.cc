#include <bits/stdc++.h>

using namespace std;

int f[1002][12];

long long int power(int a, int b){
  long long int res = 1;
  while(b > 0){
    if(b & 1) res = res * a;
    b >>= 1;
    a = a * a;
  }
  return res;
}
int fun(long n, int b, int k){
  if(n < 0) return 0;
  if(n == 0) return 1;
  if(f[n][b] != -1){
    return f[n][b];
  }
  int res = 0;
  for(int i = 1; i * i <= n && i != b; ++i){
    res += fun(n - power(i, k), i, k);
  }
  //cerr << res << endl;
  f[n][b] = res;
  return res;
}

int main(){
  int n, x;
  cin >> n >> x;
  memset(f, -1, sizeof f);
  cout << fun(n, 0, x) << endl;
  return 0;
}