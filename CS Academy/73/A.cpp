#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int two = 0, one = 0, three = 0;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i){
    if(a[i] == 2) one += 1;
    if(a[i] == 1) one += 2;
  }
  for(int i = 0; i < n; ++i){
    if(a[i] == 1) three += 1;
    if(a[i] == 0) three += 2;
    //if(a[i] > 2) two += a[i];
  }
  for(int i = 0; i < n; ++i){
    //if(a[i] < 1) one += 1 - a[i];
    if(a[i] == 2) two += 2;
    if(a[i] == 0) two += 1;
  }
  cout << min(two, min(one, three)) << endl;
  return 0;
}