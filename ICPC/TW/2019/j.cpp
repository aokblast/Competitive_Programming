#include <bits/stdc++.h>

using namespace std;

bitset<500> sets[15];


int main(){
  int tc, n, m;
  cin >> tc;
  string str;
  while(tc--){
    cin >> m  >> n;
    for(int i = 0; i < n; ++i) sets[i] = bitset<500>();
    for(int i = 0; i < n; ++i)cin >> str, sets[i] = bitset<500>(str);
    int ans = INT_MAX;
    for(int i = 0; i < (1 << n); ++i){
      int cnt = 0;
      bitset<500> s;
      for(int j = 0; j < n; ++j) if(i & (1 << j)) s |= sets[j], ++cnt;
      if(s.count() == m) ans = min(ans, cnt);
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
  }
}
