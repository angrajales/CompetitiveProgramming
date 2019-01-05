#include <bits/stdc++.h>

using namespace std;

char game[202][202];
int di[6] = {-1, -1, 0, 0, 1, 1};
int dj[6] = {-1, 0, -1, 1, 0, 1};

bool win_white(int i, int j, int n){
  if(i < 1 || j < 1 || j > n || i > n){
    return false;
  }
  if(j == n){
    return game[i][n] == 'w';
  }
  bool can = false;
  for(int dir = 0; dir < 6; ++dir){
    int new_i = i + di[dir];
    int new_j = j + dj[dir];
    if(new_i >= 1 && new_j >= 1 && new_i <= n && new_j <= n && game[new_i][new_j] == 'w'){
      can |= win_white(new_i, new_j, n); 
    }
  }
  return can;           
}
bool win_black(int i, int j, int n){
  if(i < 1 || j < 1 || j > n || i > n){
    return false;
  }
  if(i == n){
    return game[n][j] == 'b';
  }
  bool can = false;
  for(int dir = 0; dir < 6; ++dir){
    int new_i = i + di[dir];
    int new_j = j + dj[dir];
    if(new_i >= 1 && new_j >= 1 && new_i <= n && new_j <= n && game[new_i][new_j] == 'b'){
      can |= win_black(new_i, new_j, n); 
    }
  }
  return can;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int cur_game = 0;
  while(cin >> n){
    if(n == 0) return 0;
    cur_game ++;
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        cin >> game[i][j];
      }
    }
    /*bool can_white = false;
    for(int i = 1; i <= n; ++i){
      if(game[1][i] == 'b') continue;
      can_white |= win_white(1, i, n);
    }*/
    bool can_black = false;
    for(int i = 1; i <= n; ++i){
      if(game[1][i] == 'w') continue;
      can_black |= win_black(1, i, n);
    }
    cout << cur_game << " ";
    if(can_black){
      cout << "B" << endl;
    }else{
      cout << "W" << endl;
    }
  }
  return 0;
}