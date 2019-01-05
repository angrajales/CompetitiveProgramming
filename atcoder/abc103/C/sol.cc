#include <bits/stdc++.h>

using namespace std;

long long int a[3001];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  long long int res = 0;
  for(int i = 0; i < n; ++i){
    res += a[i] - 1;
  }
  cout << res << endl;
  return 0;
}
