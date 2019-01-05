#include <bits/stdc++.h>

using namespace std;

int w[100001], h[100001];

bool test(int a, int n){
  int prev = a;
  bool can = true;
  for(int i = 1; i < n; ++i){
    if(w[i] <= prev){
      if(w[i] < h[i] && h[i] <= prev){
        prev = h[i];
      }else{
        prev = w[i];
      }
    }
    else if(h[i] <= prev){
      if(h[i] < w[i] && w[i] <= prev){
         prev = w[i];
      }else{
         prev = h[i];
      }
    }else{
      can = false;
    }
  }
  return can; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> w[i] >> h[i];
  }
  if(test(w[0], n) || test(h[0], n)){
    puts("YES");
  }else{
    puts("NO");
  }
  return 0;
} 
