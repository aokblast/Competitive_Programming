#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	ll n, k;

	cin >> n >> k;

	function<string(ll, ll)> dfs = [&](ll n, ll  k){
		if(n <= 1)
			return to_string(k);
		ll cur = 1ll << (n - 1);
		if(k >= cur)
			return "1" + dfs(n - 1, (cur - 1) & ((~0ll) ^ (k - cur)));
		else
			return "0" + dfs(n - 1, k);

	};


	cout << dfs(n, k) << '\n';

}

