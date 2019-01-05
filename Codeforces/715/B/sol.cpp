#include <bits/stdc++.h>

using namespace std;

const int N = 1002;
const int inf = (1 << 30);
int d[N];
int p[N];
vector<pair<int, int> > g[N];
vector<pair<int, int> > edges;
int dijkstra(int s){
  for(int i = 0; i < N; ++i){
    d[i] = inf;
  }
  d[s] = 0;
  p[s] = -1;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  while(!pq.empty()){
    pair<int, int> next = pq.top();
    pq.pop();
    for(int i = 0; i < g[s].size(); ++i){
      int u = g[next.second][u].second;
      int weight = g[next.second][u].first;
      if(d[next.second] + weight < d[u]){
        if(weight == 0){
          edges.push_back(make_pair(next.second, u));
        }
        pq.push(make_pair(d[next.second] + weight, u));
        d[u] = d[next.second] + weight;
        p[u] = next.second;
      }
    }
  }
  return edges.size();
}

vector<int> get_path(int t){
  vector<int> path;
  while(t != -1){
    path.push_back(t);
    t = p[t];
  }
  return path;
}

int main(){
  int n, m, L, s, t;
  scanf("%d %d %d %d %d", &n, &m, &L, &s, &t);
  for(int i = 0; i < m; ++i){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].push_back(make_pair(c, b));
    g[b].push_back(make_pair(c, a));
  }
  int pre_weight = dijkstra(s);
  if(d[t] >= L || pre_weight + d[t] > L){
    return 0 * puts("-1");
  }
  vector<int> path;
  for(int i = 0; i < edges.size(); ++i){
    for(int j = 0; j + 1 < path.size(); ++j){
      pair<int, int> p = make_pair(path[j], path[j + 1]);
      if(p.first == edges[i].first && p.second == edges[i].second){
        
      }
    }
  }
  return 0;
}