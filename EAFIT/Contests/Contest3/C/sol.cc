#include <bits/stdc++.h>

using namespace std;

int turn = 1;
int win = -1;
bool solve(int a, int b){
  if(a == 0 || b == 0){
    return true;
  }
  int mx = max(a, b);
  int mn = min(a, b);
  if(turn){
    for(int i = mn; mn * i <= mx; ++i){
      if(a > b){
        bool can = solve(a - mn * i, b);
        if(can) win = 1;
        turn ^= 1;
      }else{
        bool can = solve(a, b - mn * i);
        if(can) win = 1;
        turn ^= 1;
      }
    }
  }else{
    for(int i = mn; mn * i <= mx; ++i){
      if(a > b){
        bool can = solve(a - mn * i, b);
        if(can) win = 0;
        turn ^= 1;
      }else{
        bool can = solve(a, b - mn * i);
        if(can) win = 0;
        turn ^= 1;
      }
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  while(cin >> a >> b){
    solve(a, b);
    if(win){
      cout << "1" << endl;
    }else{
      cout << "2" << endl;
    }
  }
  return 0;
}