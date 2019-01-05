#include <bits/stdc++.h>

using namespace std;

const int N = 101;
bool g[N][N];

void dfs(int s=1){
  if(was[s]){
    cnt[s] += 1;
    return;
  }
  was[s] = true;
  for(int i = 0; i < g[s].size(); ++i){
    dfs(g[s][i]);
  }
}

int main(){
  int n, b;
  while(cin >> n >> b){
    if(!n && !b) break;
    for(int i = 0; i < b; ++i){
      int a, b, t;
      cin >> a >> b >> t;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1);
    memset(was, 0, sizeof was);
    for(int i = 1; i <= n; ++i){
      if(i == 1 && cnt[1] >= 2) res = true;
      if(cnt[i] >= 1) res = true;
    }
    cout << res ? "Y": "N" << endl;
  }
  return 0;
} 