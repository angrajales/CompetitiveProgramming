#include <bits/stdc++.h>

using namespace std;

int main(){
  stack<int> s;
  int n;
  while(cin >> n){
    if(n == 0) break;
    deque<int> sim;
    for(int i = 1; i <= n; ++i){
      sim.push_back(i);
    }
    vector<int> v;
    while(sim.size() > 1){
      int t = sim.front();
      sim.pop_front();
      int nt = sim.front();
      sim.pop_front();
      v.push_back(t);
      sim.push_back(nt);
    }
    int last = sim.front();
    sim.pop_front();
    cout << "Discarded cards:";
    for(int i = 0; i < v.size(); ++i){
      if(i != 0){
         cout << ", " << v[i];
      }else{
        cout << " " << v[i];
      }
    }
    cout << endl;
    cout << "Remaining card: " << last << endl;
  }
  return 0;
}