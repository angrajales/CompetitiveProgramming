#include <bits/stdc++.h>

using namespace std;

int mm[9][38];

int main(){
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t){
    int n, m;
    cin >> n >> m;
    memset(mm, -1, sizeof mm);
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        cin >> mm[i][j];
      }
    }
    bool can = true;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(i == j && mm[i][i] != 1) can = false;
        if(i == j){
          continue;
        }
        if(j > m && i > n) continue;
        if(mm[i][j] == 1 && mm[j][i] == 1) can = false;
      }
    }
    if(can) puts("Yes");
    else puts("No");
  }
  return 0;
}