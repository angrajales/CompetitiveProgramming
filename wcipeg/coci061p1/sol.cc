#include <bits/stdc++.h>

using namespace std;

int m[42];

int main(){
  memset(m, 0, sizeof m);
  int ans = 0;
  for(int i = 0; i < 10; ++i){
    int a;
    cin >> a;
    a %= 42;
    if(!m[a]){
      m[a] = true;
      ans++;
    }
  }
  cout << ans << endl;
}