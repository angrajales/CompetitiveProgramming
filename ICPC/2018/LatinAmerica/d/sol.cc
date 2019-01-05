#include <bits/stdc++.h>

using namespace std;

set<pair<string, string> > pr;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    string prov = s.substr(s.find('@') + 1, s.size() - s.find('@'));
    string cnt = "";
    for(int j = 0; j < s.find('@'); ++j){
      if(s[j] == '+') break;
      if(s[j] == '.') continue;
      cnt += s[j];
    }
    //cerr << prov << " "  << cnt << endl;
    if(pr.count(make_pair(prov, cnt)) == 0){
      pr.insert(make_pair(prov, cnt));
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}