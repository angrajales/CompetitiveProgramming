#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  string a;
  cin >> n >> x;
  cin >> a;
  for(int i = 0; i < x; ++i){
    for(unsigned int k = 0; k < a.size(); ++k){
      if(a[k] == 'B' && a[k + 1] == 'G'){
        a[k + 1] = 'B';
        a[k] = 'G';
        ++k;
      }
    }
  }
  cout << a << endl;
  return 0;
}