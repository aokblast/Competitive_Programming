#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1e3 + 5;



int dp[MAXLEN][MAXLEN];
int prefixSum[MAXLEN];


int main(){
  int tc, n;
  scanf(" %d", &tc);
  while(tc--){
    scanf(" %d", &n);
    memset(dp, 0, sizeof(dp[0]) * n);
    memset(prefixSum, 0, 4 * n);
    for(int i = 1; i <= n; ++i)scanf(" %d", prefixSum + i), prefixSum[i] += prefixSum[i - 1];
    for(int len  = 1; len < n; ++len){
      for(int l = 1; l + len <= n; ++l){
        int r = l + len;
        register int mi = dp[l][l] + dp[l + 1][r];
        for(int k = l + 1; k < r;  ++k){
          mi = min(mi, dp[l][k] + dp[k + 1][r]);
        }
        dp[l][r] = mi + prefixSum[r] - prefixSum[l - 1];
      }
    }
    cout << dp[1][n] << "\n";
  }
}
