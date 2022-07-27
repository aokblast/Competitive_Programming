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
const ld EPointS = 1e-9;

using pii = pair<int, int>;

inline int cross(const pii &p1, const pii &p2, const pii &p3){
	return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
}

inline int dis(const pii &p1, const pii &p2){
	return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;

	cin >> n;

	pii ps[n];

	for(int i = 0; i < n; ++i)
		cin >> ps[i].first >> ps[i].second;

	pii tmp[n]; 
	int idx = 0; 

	sort(ps, ps + n);

	for(int i = 0; i < n; ++i){
		while(idx >= 2 && cross(tmp[idx - 2], tmp[idx - 1], ps[i]) <= 0)
			--idx;
		tmp[idx++] = ps[i];
	}
	int lim = idx;
	
	for(int i = n - 2; i >= 0; --i){
		while(idx > lim && cross(tmp[idx - 2], tmp[idx - 1], ps[i]) <= 0)
			--idx;
		tmp[idx++] = ps[i];
	}

	if(idx < 4){
		cout << dis(tmp[0], tmp[1]) << '\n';
		return 0;
	}

	int res = 0;
	int j = 0;
	for(int i = 1; i < idx; ++i){
		while(cross(tmp[i - 1], tmp[i], tmp[j]) <= cross(tmp[i - 1], tmp[i], tmp[(j + 1) % idx]))
			j = (j + 1) % idx;
		res = max({res, dis(tmp[i - 1], tmp[j]), dis(tmp[i], tmp[j])});
	}
	cout << res << '\n';

}
