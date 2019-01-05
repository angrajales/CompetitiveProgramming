#include <bits/stdc++.h>

using namespace std;

const int N = 100002;
vector<pair<int, int> > g[N];
long long d[N];
long long inf = (1LL << 62);
int p[N];

void dijkstra(int s) {
  for(int i = 0; i < N; i++) p[i] = -1, d[i] = inf;
  priority_queue <pair<long long,int>, vector<pair<long long,int> > , greater<pair<long long, int> > > q;
  q.push(pair<int,int>(0, s));
  d[s] = 0L;
  p[s] = -1;
  while(!q.empty()) {
    long long curr_distance = q.top().first;
    int curr_node = q.top().second;
    q.pop();
    if(curr_distance > d[curr_node]) continue;
    for(int i = 0; i < g[curr_node].size(); i++) {
      int next_node = g[curr_node][i].second; 
      long long next_weight = g[curr_node][i].first;
      if(d[next_node] > curr_distance + next_weight) {
	d[next_node] = curr_distance + next_weight;
	q.push(make_pair(d[next_node], next_node));
	p[next_node] = curr_node;
      }
    }
  }
}

vector<int> get_path(int v){
  vector<int> res;
  while(v != -1){
    res.push_back(v);
    v = p[v];
  }
  return res;
}

int main( ){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.precision( 11 );
  cout << fixed;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    int a, b, c;                
    cin >> a >> b >> c;
    g[a].push_back(make_pair(c, b));
    g[b].push_back(make_pair(c, a));
  }
  dijkstra(1);
  if(d[n] == inf){
    return 0 * puts("-1");
  }
  vector<int> res = get_path(n);
  reverse(res.begin(), res.end());
  if(res.size() > 0){
    cout << res[0];
  }
  for(int i = 1; i < res.size(); ++i){
    cout << " " << res[i];
  }
  cout << endl;
  return 0;
}
