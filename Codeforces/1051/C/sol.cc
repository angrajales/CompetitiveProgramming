#include <bits/stdc++.h>

using namespace std;

const int N = 101;

pair<vector<int>, int> fi[N];

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <101; ++i){
    fi[i].second = 0;
  }
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    fi[x].first.push_back(i);
    fi[x].second++;
  }
  int pos = 0;
  for(int i = 1; i < 101; ++i){
    if(fi[i].second == 1){
      pos++;
    }
  }
  vector<string> res(n);
  if(pos & 1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    int to_a = pos / 2;
    for(int i = 1; i < 101; ++i){
      if(fi[i].second > 1){
        for(int k = 0; k < fi[i].second; k++){
          res[fi[i].first[k]] = "A";
        }
        continue;
      }
      if(fi[i].second == 1 && to_a >= 1){
        to_a--;
        res[fi[i].first[0]] = "A";
        continue;
      }
      if(fi[i].second == 1 && to_a == 0){
        res[fi[i].first[0]] = "B";
      }
    }
    for(int i = 0; i < res.size(); ++i){
      cout << res[i];
    }
  }
  return 0;
}