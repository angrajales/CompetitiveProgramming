#include <bits/stdc++.h>

using namespace std;

const int N = 100002;
vector<int> g[N];
map<int, int> mp;
int d[N];

void dfs(int v, int p, int depth){
  d[v] = depth;
  for(int i = 0; i < g[v].size(); ++i){
    int u = g[v][i];
    if(u != p){
      dfs(u, v, depth + 1);
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 2; i <= n; ++i){
    int v;
    scanf("%d", &v);
    g[v].push_back(i);
    g[i].push_back(v);
  }
  dfs(1, -1, 0);
  mp.clear();
  for(int i = 1; i <= n; ++i){
    mp[d[i]]++;
  }
  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans = ans + (mp[i] & 1);
  }
  cout << ans << endl;
  return 0;
}