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
	int n, b[MAXN], d[MAXN];
	vector<int> res[MAXN];
	auto bfs = [&](){
		queue<pair<int, int>> q;
		q.push({0, n});
		int cur = 1;
		while(!q.empty()){
			auto [l, r] = q.front(); q.pop();
			int u = d[l];
			if(cur == n || l + 1 == r)
				continue;
			int pre = l + 1;
			++cur;
			res[u].push_back(d[l + 1]);
			for(int i = l + 2; i < r; ++i){
				if(b[cur] == d[i]){
					res[u].push_back(d[i]);
					q.push({pre, i});
					pre = i;
					++cur;
				}
			}
			if(pre < r)
				q.push({pre, r});
		}
		

	};
	while(cin >> n && n){	
		for(int i = 0; i < n; ++i)
			res[i + 1].clear(), cin >> b[i];
		for(int i = 0; i < n; ++i)
			cin >> d[i];
		bfs();
		for(int i = 1; i <= n; ++i){
			cout << i << ':';
			for(const int adj : res[i])
				cout << ' ' << adj;
			cout << '\n';
		}
	}
	


}
