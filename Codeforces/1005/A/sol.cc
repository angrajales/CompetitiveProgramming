#include <bits/stdc++.h>

using namespace std;

int a[1001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  vector<int> res;
  int last = 1;
  for(int i = 1; i < n; ++i){
    if(a[i] == 1){
      res.push_back(last);
    }
    last = a[i];
  }
  res.push_back(last);
  cout << res.size() << endl;
  for(auto &e: res){
    cout << e << " ";
  }
  return 0;
}