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

const int MAXN = 2e2 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main() {
    int tc = 1;
    int n, m;
    string res;
    bool vis[MAXN][MAXN * 4];
    int val[MAXN][MAXN * 4];
    unsigned char c;
    vector<int> holes;
    unsigned char ma2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    auto fill = [&](int x, int y){
        if(isdigit(c))
            c = ma2[c - '0'];
        else
            c = ma2[c - 'a' + 10];
        for(int i = 0; i < 4; ++i)
            val[x][y * 4 + i] = (c & (1 << (3 - i))) ? -1 : 0;

    };

    char ma[6]  = {'W', 'A', 'K', 'J', 'S', 'D'};

    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    
    function<void(int, int, int)> dfs1 = [&](int x, int y, int cur){
        if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || val[x][y] == 0)
            return;
        val[x][y] = cur;
        vis[x][y] = true;
        for(int i = 0; i < 4; ++i)
            dfs1(x + dir[i][0], y + dir[i][1], cur);
    };
    

    int r = 0;
    function<void(int, int)> dfs2 = [&](int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= m){
            r = -1;
            return;
        }
        if(vis[x][y]){
            if(val[x][y])
                r = r == -1 ? -1 : val[x][y];
            return;
        }

        vis[x][y] = true;

        for(int i = 0; i < 4; ++i)
            dfs2(x + dir[i][0], y + dir[i][1]);

        return;

    };

    while(cin >> n >> m && n && m){
        memset(vis, 0, sizeof(vis));
        memset(val, 0, sizeof(val));
        res.clear();
        holes.clear();
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                cin >> c;
                fill(i, j);
            }

        m *= 4;
        holes.push_back(0);
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!vis[i][j] && val[i][j] == -1)
                    dfs1(i, j, holes.size()), holes.push_back(0);
        for(int i = 0; i < n; ++i)
            for(int j = 0;j < m; ++j)
                if(!vis[i][j] && val[i][j] == 0){
                    r = 0;
                    dfs2(i, j);
                    if(r == -1)
                        continue;
                    ++holes[r];
                }
        
        for(int i = 1; i < holes.size(); ++i)
            res.push_back(ma[holes[i]]); 
        
        sort(res.begin(), res.end());
        
        cout << "Case " << (tc++) << ": " << res << '\n';

    }

}
