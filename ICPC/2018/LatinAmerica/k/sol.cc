#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  int rem = n;
  for(int i = 0; i < n - 1; ++i){
    if(a[i] >= a[i + 1]){
      rem--;
      cerr<< a[i] << " " << a[i+1] << endl;
    }
  }
  cout << rem << endl;
  return 0;
}
