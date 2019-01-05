#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long res = 0;
  for(int i = 1; i <= m; ++i) cin >> a[i];
  a[0] = 1;
  for(int i = 1; i <= m; ++i){
    if(a[i] >= a[i - 1]) res  += a[i] - a[i - 1];
    else res += n - a[i - 1] + a[i];
    //cerr << i << " " << res << endl;
  }
  cout << res << endl;
  return 0;
}