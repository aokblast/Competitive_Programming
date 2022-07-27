#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5;

int main(){
	int t, n;
	cin >> t;
	int pre[MAXN];
	string s1, s2;
	while(t--){
		cin >> n >> s1 >> s2;

		pre[0] = s1[0] == s2[0];

		for(int i = 1; i < n; ++i)
			pre[i] = pre[i - 1] + (s1[i] == s2[i]);

		int res = pre[n - 1], l = 0, r = 0;
		
		for(int i = 0; i < n; ++i){
			for(int j = i; j < n; ++j){
				int cur = 0;
				for(int l1 = i, l2 = j; l1 <= j; ++l1, --l2)
					cur += s1[l1] == s2[l2];
				cur += (i == 0 ? 0 : pre[i - 1]) + (j == n - 1 ? 0 : pre[n - 1] - pre[j]);
				if(cur > res){
					res = cur, l = i, r = j;
				}else if(cur == res){
					if((j - i) < (r - l))
						l = i, r = j;
				}
			}
		}

		cout << pre[n - 1] << ' ' << res << ' ' << (l + 1) << ' ' << (r + 1) << '\n';
	}
		
}
