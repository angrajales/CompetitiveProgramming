#include <bits/stdc++.h>

using namespace std;

const int N = 2 * (int) (1e5) + 2;
int in[N], out[N], sz[N];
vector<int> g[N];
vector<int> lst;
int ti = 0;

void dfs(int u, int p){
  in[u] = ti++;
  lst.push_back(u);
  sz[u] = 1;
  for(int i = 0; i < g[u].size(); ++i){
    if(g[u][i] != p){
      dfs(g[u][i], u);
      sz[u] += sz[g[u][i]];
    }
  }
  //out[u] = ti++;
}

int solve(int u, int k){
  if(k > sz[u]){
    return -1;
  }
  return lst[in[u] + k - 1];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 2; i <= n; ++i){
    int u;
    cin >> u;
    g[u].push_back(i);
  }
  dfs(1, -1);
  for(int i = 0; i < q; ++i){
    int u, k;
    cin >> u >> k;
    cout << solve(u, k) << endl;
  }
  return 0;
}