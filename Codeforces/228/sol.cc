#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u])
      dfs1(u);
  }
  order.push_back(v);
}

void dfs2(int v, int cl) {
  comp[v] = cl;
  for (int u : gt[v]) {
    if (comp[u] == -1)
      dfs2(u, cl);
  }
}

bool solve_2SAT() {
  used.assign(n, false);
  for (int i = 0; i < n; ++i) {
  if (!used[i])
    dfs1(i);
  }
  comp.assign(n, -1);
  for (int i = 0, j = 0; i < n; ++i) {
    int v = order[n - i - 1];
    if (comp[v] == -1)
      dfs2(v, j++);
  }
  assignment.assign(n / 2, false);
  for (int i = 0; i < n; i += 2) {
    if (comp[i] == comp[i + 1])
      return false;
    assignment[i / 2] = comp[i] > comp[i + 1];
  }
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m;
  cin >> n >> m;
  g.resize(2 * n + 4);
  gt.resize(2 * n + 4);
  for(int i = 0; i < m; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if(c == 1){
      g[2 * a].push_back(2 * b);
      g[2 * b].push_back(2 * a);
      gt[2 * a].push_back(2 * b);
      gt[2 * b].push_back(2 * a);
      g[2 * a + 1].push_back(2 * b + 1);
      g[2 * b + 1].push_back(2 * a + 1);
      gt[2 * a + 1].push_back(2 * b + 1);
      gt[2 * b + 1].push_back(2 * a + 1);
    }else{
      g[2 * a].push_back(2 * b + 1);
      g[2 * b].push_back(2 * a + 1);
      g[2 * a + 1].push_back(2 * b);
      g[2 * b + 1].push_back(2 * a);
      gt[2 * a].push_back(2 * b + 1);
      gt[2 * b].push_back(2 * a + 1);
      gt[2 * a + 1].push_back(2 * b);
      gt[2 * b + 1].push_back(2 * a);
    }
  }
  if(solve_2SAT()){
    int res[n];
    memset(res, -1, sizeof res);
    int ans = 0;
    for(int i = 0; i < n / 2; ++i){
      if(assignment[i]){
        res[ans++] = i;
      }
    }
    printf("%d\n", ans);
    while(--ans > -1 && res[ans] != -1){
      printf("%d ", 1 + res[ans]);
    }
  }else{
    puts("Impossible");
  }
  return 0;
}