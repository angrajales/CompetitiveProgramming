#include <bits/stdc++.h>

using namespace std;

pair<int, int> q[100001];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> q[i].first >> q[i].second;
  }
  sort(q, q + m);
  int next = -1, ans = 0;
  for(int i = 0; i < m; ++i){
    if(q[i].first < next){
      next = min(next, q[i].second);
    }else{
      next = q[i].second;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}