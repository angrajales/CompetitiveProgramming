#include <bits/stdc++.h>

using namespace std;

const int N = (1e5) + 3;

pair<int, int> pr[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r, avg;
  long long int cra = 0;
  cin >> n >> r >> avg;
  for(int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    pr[i].first = b;
    pr[i].second = a;
    cra += a;
  }
  if(cra / n >= avg) return 0 * puts("0");
  sort(pr, pr + n);
  int cnt = 0;
  long long int cur = pr[cnt].second;
  long long int to = n * avg;
  long long int res = 0;
  while(cra < to){
    long long int tok = to - cra;
    long long int tf = r - cur;
    res += min(tok, tf) * pr[cnt].first;
    to = n * avg;
    cra += min(tok, tf);
    cnt++;
    cur = pr[cnt].second;
  }
  cout << res << endl;
  return 0;
}