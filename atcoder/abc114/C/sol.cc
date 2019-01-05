#include <bits/stdc++.h>

using namespace std;

int pos[] = {3, 5, 7};

inline bool alldigits(long long N){
  long long n = N;
  int pt[3] = {0, 0, 0};
  while(n > 0){
    if(n % 10 == 3){
      pt[0] ++;
    }else
    if(n % 10 == 5){
      pt[1] ++;
    }else{
      pt[2] ++;
    }

    n /= 10;
  }
  return pt[0] > 0 && pt[1] > 0 && pt[2] > 0;
}

int ways = 0;

long long n;

void solve(long long cur){
  if(cur > n) return;
  if(alldigits(cur)) ways += 1;
  for(int i = 0; i < 3; ++i){
     solve(cur * 10 + pos[i]);
  }
}


int main(){
  cin >> n;
  solve(3);
  solve(5);
  solve(7);
  cout << ways << endl;
  return 0;
}