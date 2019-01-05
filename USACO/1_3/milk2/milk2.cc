#include <bits/stdc++.h>

using namespace std;

/*
  ID: andergr2
  LANG: C++
  TASK: milk2
*/

pair<int, int> intervals[5001];

#define DEBUG 0

int main(){
  int n;
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> intervals[i].first >> intervals[i].second;
  } 
  sort(intervals, intervals + n);
  int l = intervals[0].first;
  int h = intervals[0].second;
  int maxL = h - l;
  cerr << maxL << endl;
  int maxR = 0;
  for(int i = 1; i < n; ++i){
    pair<int, int> p = intervals[i];
    if(p.first <= h){
      h = max(p.second, h);
    }else{
      maxL = max(maxL, h - l);
      maxR = max(maxR, p.first - h);
      l = p.first;
      h = p.second;
    }
  }
  cout << maxL << " " << maxR << endl;
  return 0;
}