#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;                        
  cin >> n;
  string res = "";
  for(int i = 1; res.size() <= 1000; i++){
    res += to_string(i);
  }
  cout << res[n - 1] << endl;
  return 0;
}