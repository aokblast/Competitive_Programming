#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	ll n;
	cin >> n;

	int a[n + 1], b[n + 1];
	bool vis[n + 1];
	memset(vis, 0, sizeof(vis));

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i)
		cin >> b[i];

	unordered_map<int, vector<int>> mp;

	vector<int> bases;


	for(int i = 2; i <= n; ++i){
		if(vis[i])
			continue;
		ll tmp = i;

		bases.push_back(i);
		while(tmp <= n){
			vis[tmp] = true;
			mp[i].push_back(tmp);
			tmp *= i;
		}
	}

	ll res = 0;

	for(const int base : bases){
		int sz = mp[base].size();
		const auto &c = mp[base];
		int lim = (1 << sz);
		ll cur = 0;

		for(int i = 0; i < lim; ++i){
			ll tmp = 0;
			vector<int> poses;
			for(int j = 0; j < sz; ++j)
				if(i & (1 << j))
					tmp += a[c[j]], poses.push_back(j);
			for(int j = 0; j < poses.size(); ++j)
				for(int k = j + 1; k < poses.size(); ++k)
					if((poses[k] + 1) % (poses[j] + 1) == 0)
						tmp -= b[c[poses[k]]];

			cur = max(cur, tmp);
		}

		res += cur;
		
	}
	res += a[1];
	cout << res << '\n';




}
