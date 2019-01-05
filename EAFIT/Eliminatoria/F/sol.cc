#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> g[N];
vector<int> order, comp;
bool was[N];

void dfs1(int s){
  if(was[s]){
    return;
  }
  was[s] = true;
  for(int i = 0; i < g[s].size(); ++i){
    dfs1(g[s][i]);
  }
  order.push_back(s);
}

void dfs2(int s){
  if(was[s]){
    return;
  }
  comp.push_back(s);
  was[s] = true;
  for(int i = 0; i < g[s].size(); ++i){
    dfs2(g[s][i]);
  }
}

int main(){
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t){
    int n, s, l;
    cin >> n >> s >> l;
    memset(was, 0, sizeof was);
    order.clear();
    comp.clear();
    for(int i = 0; i <= n + 1; ++i){
      g[i].clear();
    }
    for(int i = 0; i < s; ++i){
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
    }
    int res = 0;
    for(int i = 1; i <= l; ++i){
      int kn;
      cin >> kn;
      if(!was[kn]){
        dfs1(kn);
        //res++;
      }
    }
    memset(was, 0, sizeof was);
    for(int i = 1; i <= n; ++i){
      int v = order.back();
      order.pop_back();
      if(!was[v]) res++, dfs2(v);
    }
    cout << res << endl;
  }
  return 0;
}