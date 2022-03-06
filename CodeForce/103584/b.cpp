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

const int MAXN = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	pair<int, int> gs[MAXN], ts[MAXN];
	auto dis = [](const pair<int, int> &p1, const pair<int, int> &p2){
		return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
	};
	for(int i = 0; i < n; ++i)
		cin >> gs[i].first >> gs[i].second;
	for(int i = 0; i < m; ++i)
		cin >> ts[i].first >> ts[i].second;
	sort(ts, ts + m);
	for(int i = 0; i < n; ++i){
		int res = 0;
		for(int j = 0; j < n; ++j){
			if(dis(gs[i], ts[res]) > dis(gs[i], ts[j]))
				res = j;
		}
		cout << ts[res].first << ' ' << ts[res].second << '\n';
		

	}


}
