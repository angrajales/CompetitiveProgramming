#include <bits/stdc++.h>

using namespace std;

const int N = 10002;
vector<int> g[N];
int color[N];
int ncolor[N];


int paint(int v, int c, int p){
  for(int i = 0; i < g[v].size(); ++i){
    int u = g[v][i];
    if(p != u){
      ncolor[u] = c;
      paint(u, c, v);
    }
  }
}

int res = 0;

void dfs(int v, int p){
  if(color[v] != ncolor[v]) res++;
  ncolor[v] = color[v];
  paint(v, color[v], p);
  for(int i = 0; i < g[v].size(); ++i){
    int u = g[v][i];
    if(u != p){
      dfs(u, v);
    }
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 2; i <= n; ++i){
    int a;
    cin >> a;
    g[a].push_back(i);
    g[i].push_back(a);
  }
  for(int i = 1; i <= n; ++i){
    int c;
    cin >> c;
    color[i] = c;
  }
  memset(ncolor, 0, sizeof ncolor);
  dfs(1, -1);
  cout << res << endl;
  
} 