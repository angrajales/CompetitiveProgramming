#include <bits/stdc++.h>

using namespace std;

int a[100001];
int b[100001];
map<int, int> mp;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  for(int i = 0; i < n; ++i) mp[b[i]] = i;
  for(int i = 0; i < n; ++i) a[i] = mp[a[i]];
  int l = -1, r = -1;
  for(int i = 0; i < n - 1; ++i){
    if(a[i] != i){
      l = i;
      break;
    }
  }
  for(int i = n - 1; i >= 0; --i){
    if(a[i] != i){
      r = i;
      break;
    }
  }
  if(l == -1 || r == -1){ 
    cout << "yes" << endl;
    cout << "1 1";
    return 0;
  }
  reverse(a + l, a + r + 1);
  bool can = true;
  for(int i = 0; i < n - 1; ++i){
    if(a[i] > a[i + 1]){
      can = false;
    }
  }
  if(can){
    cout << "yes" << endl;
    cout << l + 1 << " " << r + 1 << endl; 
  }else{
    puts("no");
  }
  return 0;
}