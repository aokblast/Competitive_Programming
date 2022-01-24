#include <bits/stdc++.h>

using namespace std;
const int MAXLEN = 1e5 + 5;

int n, d, arr[MAXLEN];



bool solve(){
  static vector<int> idx;
  idx.clear();
  for(int i = 0; i < n - 1; ++i){
    if(abs(arr[i] - arr[i  + 1]) > d) idx.push_back(i);
  }
  int sz = idx.size();
  if(sz == 0){
    return 1;
  }else if(sz == 1){
    return ((idx[0] > 0 &&  abs(arr[idx[0] + 1] - arr[idx[0] - 1] <= 2 * d)) || (abs(arr[idx[0] + 2] - arr[idx[0]] <= 2 * d) ));  
  }else if(sz == 2){
    return ((idx[1] - idx[0] == 1)&& abs(arr[idx[0]] - arr[idx[1] + 1]) <= 2 *d );
  }else{
    return 0;
  }

}


int main(){
  
  while(cin >> n && n && cin >> d){
    for(int i = 0;i  < n; ++i){
      cin >> arr[i];
    }
    cout << (solve() ? "Y" : "N") << '\n';
  }
}
