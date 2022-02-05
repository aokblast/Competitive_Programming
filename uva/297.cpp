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

const int MAXN = 2e4 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


int main() {
    int tc = 1;
    cin >> tc;
    int t1[MAXN][5], t2[MAXN][5];
    int res, idx, tot; 
    string s;
    function<int(int [MAXN][5])> build = [&](int t[MAXN][5]){
        int cur = ++tot;
        switch(s[idx]){
            case 'p':{
                ++idx;
                for(int i = 0; i < 4; ++i)
                      t[cur][i] = build(t);
                t[cur][4] = 1;
                break;
            }
            case 'e':{
                ++idx;
                break;
            }
            case 'f':{
                ++idx;
                t[cur][0] = 1;
                break;
            }
        }
        return cur;
    };
    
    function<void(int, int, int)> dfs = [&](int cur, int u, int v){
        if(t1[u][4] && t2[v][4])
            for(int i = 0; i < 4; ++i)
                dfs(cur >> 2, t1[u][i], t2[v][i]);
        else if(t1[u][4] && !t2[v][4]){
            if(t2[v][0])
                res += cur;
            else
                for(int i = 0; i < 4; ++i)
                    dfs(cur >> 2, t1[u][i], v);
        }else if(!t1[u][4] && t2[v][4]){
            if(t1[u][0])
                res += cur;
            else
                for(int i = 0; i < 4; ++i)
                    dfs(cur >> 2, u, t2[v][i]);
        
        }else{
            res += (t1[u][0] || t2[v][0]) ?  cur : 0;
        }

    };


    for (int t = 1; t <= tc; t++) {
        memset(t1, 0, sizeof(t1));
        memset(t2, 0, sizeof(t2));
        
        cin >> s;
        tot = 0;
        idx = 0;
        build(t1);

        cin >> s;
        idx = 0;
        tot = 0;
        build(t2);

        res = 0;
        dfs(1 << 10, 1, 1);
        cout << "There are " << res << " black pixels.\n";

    }
}
