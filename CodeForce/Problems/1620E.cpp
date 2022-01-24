#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 5e5 + 5;

int arr[MAXLEN];
vector<int> djs[MAXLEN];

int main(){
  int q, a, b, o, n = 0, ma = 0;
  cin >> q;
  while(q--){
    cin >> o;
    if(o == 1){
      cin >> a;
      ma = max(ma, a);
      djs[a].push_back(n++);    
    }else{
      cin >> a >> b;
      ma = max(ma, max(a, b));
      if(a == b) continue;
      if(djs[a].size() <= djs[b].size()){
        for(const int u : djs[a])djs[b].push_back(u);
        djs[a].clear();
      }else{
        for(const int u : djs[b]) djs[a].push_back(u);
        djs[b].clear();
        swap(djs[a], djs[b]);
      }

    }
  }
  for(int i =  0; i  <= ma; ++i){
    for(const int u : djs[i])arr[u] = i;
  }
  for(int i = 0; i < n; ++i){
    cout << arr[i] << ' ';
  }
  cout << '\n';
}
