#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	int n, m, u, v, c;

	cin >> n >> m;

	vector<pair<int, int>> edges[n + 1];

	ll flow = 0;
	while(m--){
		cin >> u >> v >> c;
		edges[u].push_back({v, c});
		flow += c;
	}

	vector<int> lian[edges[1].size()];

	int tot = 0;

	function<void(int)> dfs = [&](int u){
		for(const auto [v, w] : edges[u]){
			lian[tot].push_back(w);
			dfs(v);
		}
	};

	int len;
	ll diff[n];
	memset(diff, 0, sizeof(diff));
	for(const auto [u, w] : edges[1]){
		lian[tot].push_back(w);
		dfs(u);
		sort(lian[tot].begin(), lian[tot].end());
		len = lian[tot].size();
		flow -= 1ll * lian[tot][0] * len;
		for(int j = 0; j < len - 1; ++j)
			diff[j] += lian[tot][j + 1] - lian[tot][j];
		++tot;
	}

	n = edges[1].size();

	ll res = 0;

	for(int i = 0; i < len; ++i){
		if(flow < len)
			break;
		ll cur = min(diff[i], flow / len);
		res += 1ll * cur * (i + 1);
		flow -= 1ll * cur * len;	
	}
	
	cout << res << '\n';
}
