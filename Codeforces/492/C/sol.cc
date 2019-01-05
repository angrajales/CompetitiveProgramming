#include <bits/stdc++.h>

using namespace std;

const int N = 100002;

pair<int, int> e[N];

int main(){
  long long n, r, avg;
  cin >> n >> r >> avg;
  long long done = 0;
  for(int i = 0; i < n; ++i){
    int x, y;
    cin >> x >> y;
    e[i].first = y;
    e[i].second = x;
    done += x;
  }
  //cerr << done << endl;
  long long left = 1LL * (avg * n) - done;
  //cerr << left << endl;
  long long res = 0;
  sort(e, e + n);
  for(int i = 0; i < n; ++i){
    long long have = (r - e[i].second);
    long long required = max(0LL, min(left, have));
    res += 1LL * required * e[i].first;
    left -= required; 
  }
  cout << res << endl;
  return 0;
}