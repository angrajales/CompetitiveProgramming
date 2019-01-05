#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;                        
  cin >> n >> m;
  if(n > m){
    return 0 * puts("YES");
  }
  bitset<3000> bt;
  for(int i = 0; i < n; ++i){
    int a;
    scanf("%d", &a);
    bt |= bt << (a % m);
    bt |= bt >> m;
    bt.set(a % m);
  }
  if(bt[0]) puts("YES");
  else puts("NO");
  return 0;
}