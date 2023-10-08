#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> mp;
unordered_set<long long> vis;
vector<int> cur;

void dfs(int rem, long long prod) {
		if(prod > 1000000000)
				return;
		if(vis.count((long long)rem * 1000000000 + prod))
				return;
		if(rem == 0) {
				mp[prod] = cur;
				return;
		}
		for(int i = 1; i <= rem; ++i) {
				cur.push_back(i);
				dfs(rem - i, prod * i);
				cur.pop_back();
		}
		vis.insert((long long)rem * 1000000000 + prod);
}


void pre_calc() {
		dfs(41, 1);
}

void solve() {
		int n;
		cin >> n;
		if(mp.count(n)) {
				cout << mp[n].size();
				for (const auto v : mp[n]) {
						cout << ' ' << v;
				}
				cout << endl;
		} else {
				cout << "-1" << endl;
		}
}


int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr), cout.tie(nullptr);
		int tc;
		cin >> tc;

		pre_calc();
		for(int i = 1; i <= tc; ++i) {
				cout << "Case #" << i << ": ";
				solve();
		}
		return 0;
}
