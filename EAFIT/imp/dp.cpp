#include <iostream>

using namespace std;

int solve(int S, int id){
  if(S == 0 && id >= 0){
    return 1;
  }
  if(S < 0){
    return 0;
  }
  if(S > 0 && id > 1){
    return 0;
  }

}

int main(){
  return 0;
}