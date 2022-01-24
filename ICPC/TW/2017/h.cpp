#include <bits/stdc++.h>

using namespace std;

long long ans = 0;



void dfs(long long n, unordered_map<long long, int> &s, unordered_set<long long> &visit, int layer = 1){
  long long sq = sqrt(n);
  bool isPrime = true;
  s[n] = layer;
  for(int i = 2; i <= sq; ++i){
    if(!(n % i)){
      isPrime = false;
      if(s.find(n / i) == s.end() || s[n / i] == s[n] + 1){ans += 1;
        if(visit.find(n / i) == visit.end())dfs(n / i, s, visit, layer + 1);}
      if((s.find(i) == s.end() || s[i] == s[n] + 1) && (i * i) != n){ans += 1;
        if(visit.find(i) == visit.end())dfs(i, s, visit, layer + 1);
      }
    }
  }

  if(isPrime){
    ans += visit.find(n) == visit.end();
  }
  visit.insert(n);
  cout << 
}

int main(){
  int tc, n;
  cin >> tc;
  while(tc--){
    cin >> n;
    unordered_map<long long, int> s;
    unordered_set<long long> vis;
    ans = 0;
    dfs(n, s, vis);
  
    cout << ans << '\n';
  }
}
