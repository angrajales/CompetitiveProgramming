#include <bits/stdc++.h>

using namespace std;

int a[101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;
  cin >> n >> d;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  sort(a, a + n);
  int res = 1;
  for(int i = 1; i < n; ++i){
     if(a[i-1] + d <= a[i]){
       res++;
     }
  }
  cout << res + 1 << endl;
  return 0;
}