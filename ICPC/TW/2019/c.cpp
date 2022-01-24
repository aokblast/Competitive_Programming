#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 50;

int arr[MAXLEN];

int main(){
  int n;
  cin >> n;
  for(int i =0; i < n; ++i){
    cin >> arr[i];
  }
  for(int i = 0; i < n; ++i){
    
    for(int j = 0; j < n; ++j){
      if(i == j)continue;
      for(int k = 0; k < n; ++k){
        if(i == k || j == k)continue;
        if(((abs(arr[i] - arr[j]))) % arr[k] != 0){
          cout << "no\n";
          return 0;
        }
      }
    }
  }
  cout << "yes\n";

}
