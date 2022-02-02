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

const int MAXN = 1e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



int main() {
    int tc = 1;
    // cin >> tc;
    string in, post;
    int l[MAXN], r[MAXN];
    vector<int> inv, postv;

    function<int(int, int, int, int)> build = [&](int li, int ri, int lp, int rp){
        if(li > ri)
            return 0;
        int val = postv[rp], idx = li;
        while(val != inv[idx])
            ++idx;
        int cnt = idx - li;
        l[val] = build(li, idx - 1, lp, lp + cnt - 1);
        r[val] = build(idx + 1, ri, lp + cnt, rp - 1);
        return val;

    };

    int res = INT_MAX;
    int cur = INT_MAX;

    function<void(int, int)> dfs = [&](int u, int sum){
        if(!u)
            return;
        sum += u;
        if(!l[u] && !r[u]){
            if(sum < cur)
                cur = sum, res = u;
            else if(sum == cur)
                res = min(res, u);
            return;
        }
        dfs(l[u], sum);
        dfs(r[u], sum);
    };


    while(getline(cin, in) && getline(cin, post)){
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        stringstream ssi(in), ssp(post);
        int val = 0;
        inv.clear(), postv.clear();
        
        while(ssi >> val)
            inv.push_back(val), ssp >> val, postv.push_back(val);
        int n = inv.size();
        res = INT_MAX;
        cur = INT_MAX;
        int root = build(0, n - 1, 0, n - 1);
        
        dfs(root, 0);

            
        cout << res << '\n';
        
    }
}
