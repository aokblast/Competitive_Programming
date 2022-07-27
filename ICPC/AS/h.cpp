#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 2e5 + 5;


ll exgcd(ll a ,ll b, ll &x, ll &y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

int main() {
	int tc, n;

	ll mod = 0;
	cin >> tc;
	unordered_map<ll, int> st;
	
	ll a[MAXN], inv[MAXN];

	auto Inv = [&](ll num){
		ll x = 0, y = 0;
		exgcd(num, mod, x, y);
		return x % mod;	
	};

	auto cnt = [&](int q){
		unordered_map<ll, int> mp;
		int res = 0;
		if(q == 1){
			for(int i = n - 1; i >= 0; --i)
				res = max(res, ++mp[a[i]]);
			return res;
		}
		for(int i = n - 1; i >= 0; --i){
			mp[a[i]] = 1;
			res = max(res, mp[a[i]] = max(mp[(a[i] * q) % mod] + 1, mp[a[i]]));
		}

		return res;
	};

	

	while(tc--){
		int res = 0;

		cin >> n >> mod;

		for(int i = 0; i < n; ++i){
			cin >> a[i];
			inv[i] = Inv(a[i]);
		}

		for(int i = 0; i < n - 1; ++i){
			ll cur = (a[i + 1] * inv[i]) % mod;
			if(cur < 0)
				cur += mod;
			st[cur]++;
		}

		for(int i = 0; i < n - 2; ++i){
			ll cur = (a[i + 2] * inv[i]) % mod;
			if(cur < 0)
				cur += mod;
			st[cur]++;
		}
		for(const auto [q, cur] : st){
			if(cur >= n / 4 - 3)
				res = max(res, cnt(q));
		}
		
		cout << (res >= (n + 1) / 2 ? res : -1) << '\n';

		st.clear();
	}	
}
