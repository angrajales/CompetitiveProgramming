#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int a[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  int l = 0, sl = 0, sr = 0, r = n - 1, alice = 0, bob = 0;
  while(l <= r && l < n && r >= 0){
    if(l == r){
      if(sl <= sr){
        alice++;
      }else{
        bob++;
      }
      l++;
      r--;
      continue;
    }
    if(l == r + 2){
      if(sl <= sr){
        alice++;
      }else{
        bob++;
      }
      continue;
    }
    if(sl < sr){
      sl += a[l];
      alice++;
      l++;
      continue;
    }
    if(sr < sl){
      sr += a[r];
      bob++;
      r--;
      continue;
    }
    if(sl == sr){
      sr += a[r];
      sl += a[l];
      alice++, bob++;
      l++, r--;
    }
  }
  cout << alice << " " << bob << endl;
  return 0;
}            