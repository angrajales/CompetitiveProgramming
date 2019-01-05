#include <bits/stdc++.h>

using namespace std;
int main(){
  string s;
  while(getline(cin, s)){
    istringstream ss(s);
    string p;
    vector<string> v;
    while(ss >> p){
      v.push_back(p);
    }
    reverse(v[0].begin(), v[0].end());
    cout << v[0];
    for(int i = 1; i < v.size(); ++i){
      reverse(v[i].begin(), v[i].end());
      cout << " " << v[i];
    }
    cout << endl;
  }
}