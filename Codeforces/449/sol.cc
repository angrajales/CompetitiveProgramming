#include <bits/stdc++.h>

using namespace std;

const int 


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i){
     int a, b, w;
     cin >> a >> b >> w;
     g[a].push_back(make_pair(w, b));
     g[b].push_back(make_pair(w, a));
  }
  for(int i = 0; i < k; ++i){
    int a, c;
    cin >> a >> c;
    dist2[a] = c;
  }

  return 0;
}