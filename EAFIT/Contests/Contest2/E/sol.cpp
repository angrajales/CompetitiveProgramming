#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int a[N];
bool included[601];

int main( ){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.precision( 11 );                                                             
  cout << fixed;
  int n, mx = -1;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int ways = 0;
  memset(included, 0, sizeof included);
  for(int i = 0; i < n; ++i){
    if(a[i] != 0 && !included[a[i]]){ 
      included[a[i]] = true;
      ways++;
    }
  }
  cout << ways << endl;
  return 0;
}