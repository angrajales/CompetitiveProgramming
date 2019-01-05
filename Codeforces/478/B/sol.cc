#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long kmin = 0;
  long long kmax = 0;
  int p1 = n % m;
  int p2 = n / m;
  int p3 = m - p1;
  kmin = 1LL * p1 * (p2 + 1) * p2 / 2;
  kmin += 1LL * p3 * p2 * (p2 - 1LL) / 2; 
  int q1 = n - m + 1;
  kmax = 1LL * q1 * (q1 - 1LL) / 2;
  cout << kmin << " " << kmax << endl;
  return 0;
}