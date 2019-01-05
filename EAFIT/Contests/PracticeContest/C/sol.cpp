#include <bits/stdc++.h>

using namespace std;

const int inf = (1 << 29);
const int N = 102;
int d[N][N];

int main(){
  int T;
  cin >> T;
  for(int tt = 0; tt < T; ++tt){
    int n, e, t, m;
    cin >> n >> e >> t >> m;
    memset(d, 63, sizeof d);
    for(int i = 0; i < m; ++i){
      int a, b, w;
      cin >> a >> b >> w;
      d[a][b] = w;
    }
    for(int i = 1; i <= n; ++i) d[i][i] = 0;
    for(int i = 1; i <= n; ++i){
      for(int u = 1; u <= n; ++u){
        for(int v = 1; v <= n; ++v){
          if(d[u][i] + d[i][v] < d[u][v]){
            d[u][v] = d[u][i] + d[i][v];
          }
        }
      }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i){
      if(d[i][e] <= t){
        res++;
      }
    }
    cout << res << endl;
    if(tt != T-1) cout << endl;
  }
  return 0;
}