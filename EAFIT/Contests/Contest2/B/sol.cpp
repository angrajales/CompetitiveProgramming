#include <bits/stdc++.h>

using namespace std;

const int inf = (1 << 30);

map<string, string> parent;
map<string, int> dist;
map<string, vector<string> > g;
set<string> belongs;
set<string> was;
vector<pair<string, string> > bfs(string from, string to){
  vector<pair<string, string> > res;
  dist[from] = 0;
  queue<string> q;
  q.push(from);
  was.insert(from);
  parent[from] = "noparent";
  while(!q.empty()){
    string next = q.front();
    q.pop();
    for(int i = 0; i < g[next].size(); ++i){
      string u = g[next][i];
      if(was.count(u) == 0){
        was.insert(u);
        dist[u] = dist[next] + 1;
        parent[u] = next;
        q.push(u);
      }
    }
  }
  if(belongs.count(to) == 0 || dist[to] >= inf) return res;
  while(to != "" && parent[to] != "" && to != "noparent" && parent[to] != "noparent"){
    res.push_back(make_pair(parent[to], to));
    to = parent[to];
    //cerr << to << endl;
  }
  return res;
}

int main( ){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.precision( 11 );
  cout << fixed;
  int n;
  int test = 0;
  while(cin >> n){
    test++;
    g.clear();
    dist.clear();
    parent.clear();
    was.clear();
    for(int i = 0; i < n; ++i){
      string from, to;
      cin >> from >> to;
      g[from].push_back(to);
      g[to].push_back(from);
      parent[to] = "noparent";
      parent[from] = "noparent";
      dist[from] = inf;
      dist[to] = inf;
      belongs.insert(from);
      belongs.insert(to);
    }
    string f_from, t_to;
    cin >> f_from >> t_to;
    vector<pair<string, string> > res = bfs(f_from, t_to);
    reverse(res.begin(), res.end());
    if(test > 1) cout << endl;
    if(res.size() == 0){
      cout << "No route" << endl;
    }else{
      for(int i = 0; i < res.size(); ++i){
        cout << res[i].first << " " << res[i].second << endl;
      }
    }
  }
  return 0;
}