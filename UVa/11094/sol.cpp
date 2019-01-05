#include <bits/stdc++.h>

using namespace std;

char mat[21][21];
bool was[21][21];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j, int m, int n, char base_char){
  int cnt = 0;
  was[i][j] = true;
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  while(!q.empty()){
    cnt++;
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; ++i){
      int new_x = x + dx[i];
      int new_y = y + dy[i] + n;
      new_y %= n;
      if(new_x >= 0 && new_y >= 0 && new_x < m && new_y < n && was[new_x][new_y] == false && mat[new_x][new_y] == base_char){
        q.push(make_pair(new_x, new_y));
        //cerr << "x: " << new_x << ", y: " << new_y << endl;
        was[new_x][new_y] = true;
      }
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  while(cin >> m >> n){
    for(int i = 0; i < m; ++i){
      for(int j = 0; j < n; ++j){
        cin >> mat[i][j];
      }
    }
    memset(was, 0, sizeof was);
    int i, j;
    cin >> i >> j;
    char base_char = mat[i][j];
    int ss = bfs(i, j, m, n, base_char);
    int res = 0;
    for(int ki = 0; ki < m; ++ki){
      for(int kj = 0; kj < n; ++kj){
        if(mat[ki][kj] != base_char || was[ki][kj]) continue;
        res = max(res, bfs(ki, kj, m, n, base_char));
      }
    }
    cout << res << endl;
  }
  return 0;
}