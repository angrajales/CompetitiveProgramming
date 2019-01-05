#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
const int inf = N * 1000;

vector<int> g[N];
int d[N];

void bfs(int v){
  memset(d, inf, sizeof d);
  d[v] = 0;
  deque<int> q;
  q.push_front(v);
  while(!q.empty()){
    int s = q.front();
    q.pop_front();
    for(int i = 0; i < g[s].size(); ++i){
      int n = g[s][i];
      if(d[s] + 1 < d[n]){
        d[n] = d[s] + 1;
        q.push_front(n);
      }
    }
  }
}

int diameter(int n){
  int v, u, w;
  v = u = w = 0;
  bfs(v);
  for(int i = 0; i < n; ++i){
    if(d[i] > d[u]){
      u = i;
    }
  }
  bfs(u);
  for(int i = 0; i < n; ++i){
    if(d[i] > d[w]){
      w = i;
    }
  }
  return d[w];
}

int main(){
  int n;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 1; i < n; ++i){
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << diameter(n) << endl;
}