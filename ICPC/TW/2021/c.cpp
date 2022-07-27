#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

long dp[1 << 16][200];

int main(){
	int D, K;
	cin >> D >> K;
	int digs[D];
	for(int i = 0; i < D; ++i)
		cin >> digs[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;


	for(int i = 0; i < (1 << D); ++i){
		for(int j = 0; j < K; ++j){
			if(dp[i][j] == -1)
				continue;

			for(int k = 0; k < D; ++k){
				if(i & (1 << k))
					continue;
				int newI = i | (1 << k), newN = (j * 10 + digs[k]) % K;
				dp[newI][newN] = max(dp[newI][newN], dp[i][j] * 10 + digs[k]);
			}
		}
	}

	int lim = (1 << D) - 1;

	for(int i = K - 1; i >= 0; --i){
		if(dp[lim][i] != -1){
			cout << dp[lim][i] << '\n';
			break;
		}
	}
	
}
