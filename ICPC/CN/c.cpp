#include <bits/stdc++.h>
#define int long long

const int MAXLEN = 1e5 + 5;
using namespace std;

char str[MAXLEN];

const int MOD  = 1e9 + 7;

int power(int a, int b){
  int ans = 1;
  while(b){
    if(b & 1)ans = (ans * a) % MOD;
    b >>= 1;
    a = (a * a) % MOD;
  }
  return ans;
}

signed main(){
  int tc;
  cin >> tc;
  while(tc--){
    int ans = 0;
    int x = 0, y = 0;
    scanf(" %s", str);
    int n = strlen(str);
    for(int i = n - 1; i >= 0; --i){
      if(str[i] == '1')ans = (ans + power(2, x) * power(3, y)) % MOD;
      if(str[i] == '0')++x;
      else ++y;
    }
    cout << ans + 1 << '\n';
  }
  
}
