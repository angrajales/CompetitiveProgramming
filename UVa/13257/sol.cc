#include <bits/stdc++.h>

using namespace std;

const int N = 100002;
int f[N][4];
int pos[N];
//int f[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  int res = 0;
  for(int t = 0; t < T; ++t){
    string s;
    cin >> s;
    s = "s" + s;
    memset(f, 0, sizeof f);
    memset(pos, 0, sizeof pos);
    for(int i = 0; i < s.size(); ++i){
      pos[s[i] - 'A'] = 0;
    }
    f[0][3] = 1;
    f[0][2] = 0;
    f[0][1] = 0;
    f[0][0] = 0;
    for(int i = 1; i < int(s.size()); ++i){
      for(int j = min(3, i); j >= 1; --j){
        f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        if(pos[s[i]-'A'] > 0){
          f[i][j] -= f[pos[s[i]-'A'] - 1][j - 1];
        }
      }
      pos[s[i] - 'A'] = i;
    }
    cout << f[s.size() - 1][3] << endl;
    //cout << f[s.size()][3] << endl;
  }
  return 0;
}