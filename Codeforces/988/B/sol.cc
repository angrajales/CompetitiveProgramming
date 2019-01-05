#include <bits/stdc++.h>

using namespace std;

string _s[101];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> _s[i];
  }
  sort(_s, _s + n);
  bool can = true;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      size_t found = _s[i].find(_s[j]);
      if(found == string::npos){
        can = false;
      }
    }
  }

  puts(can ? "YES": "NO");
  return 0;
}