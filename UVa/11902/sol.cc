#include <bits/stdc++.h>

using namespace std;
const int N = 101;
vector<int> g[N];
bool was[N];

bool ans[N][N];

void dfs(int s, vector<int> &pn){
  if(was[s]) return;
  for(int i = 0; i < g[s].size(); ++i){
    for(auto &x: pn){
      ans[s][pn] = true;
    }
    dfs(g[s][i]);
  }
}


int main(){
  int n, m;

  return 0;
}