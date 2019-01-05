#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string res = "None";
  int mx = 0;
  for(int i = 0; i < n; ++i){
    string a;
    int w, l;
    cin >> a >> w >> l;
    if(l == 0){
      if(w >= mx){
        mx = w;
        res = a;
      }
    }
  }
  cout << res << endl;
  return 0;
}