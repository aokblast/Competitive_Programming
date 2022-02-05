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

const int MAXN = 10 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


struct E{
    int x, y, d;
};


int main() {
    int tc = 1;
    // cin >> tc;
    char D[] = "NESW", W[] = "LRF";
    string maze, ele;
    auto getD = [&](const char c){return strchr(D, c) - D;};
    auto getW = [&](const char c){return strchr(W, c) - W;};
    int x, y, sx, sy, tx, ty;
    char sd;
    bool vis[MAXN][MAXN][4];
    int DIRS[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    E p[MAXN][MAXN][4];
    bool edges[MAXN][MAXN][4][3];
    auto next = [&](const E &e, int d) -> E{
        int nd;
        if(d == 0){
            nd = (e.d - 1 + 4) % 4;
        }else if(d == 1){
            nd = (e.d  + 1) % 4;
        }else{
            nd = e.d;
        }
        return {e.x + DIRS[nd][0], e.y + DIRS[nd][1], nd};
    };

    vector<E> res;
    function<void(const E &)> print = [&](const E &e){
        if(e.x == 0 && e.y == 0 && e.d == 0)
            return;
        print(p[e.x][e.y][e.d]);
        res.push_back(e);
    };

    auto bfs = [&](){
        sd = getD(sd);
        memset(vis, 0, sizeof(vis));
        memset(p, 0, sizeof(p));
        queue<E> q;
        q.push({sx + DIRS[sd][0], sy + DIRS[sd][1], sd});
        if(sx + DIRS[sd][0] == tx && sy + DIRS[sd][1] == ty){
            res.clear();
            res.push_back({sx, sy, sd});
            res.push_back(q.front());
            return true;
        }
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto top = q.front(); q.pop();
                for(int i = 0; i < 3; ++i){
                    auto ntop = next(top, i);
                    if(ntop.x <= 0 || ntop.y <= 0 || ntop.x > 9 || ntop.y > 9 || vis[ntop.x][ntop.y][ntop.d] || !edges[top.x][top.y][top.d][i])
                        continue;
                    if(ntop.x == tx && ntop.y == ty){
                        p[ntop.x][ntop.y][ntop.d] = top;
                        res.clear();
                        res.push_back({sx, sy, sd});
                        print(ntop);
                        return true;
                    }
                    q.push(ntop);
                    p[ntop.x][ntop.y][ntop.d] = top;
                    vis[ntop.x][ntop.y][ntop.d] = true;

                }
            }
        }
        return false;

    };

    while(cin >> maze){
        if(maze == "END")
            break;
        cin >> sx >> sy >> sd >> tx >> ty;
        memset(edges, 0, sizeof(edges));
        while(cin >> x && x && cin >> y){
            while(cin >> ele){
                if(ele == "*")
                    break;
                
                stringstream ss(ele);
                
                char a, b;
                ss >> a;
                a = getD(a);
                while(ss >> b){
                    b = getW(b);
                    edges[x][y][a][b] = true;
                }
                
            }

        }
        cout << maze << '\n';
        cout << ' ';
        if(bfs()){
            int cnt = 0;
            for(const auto e : res){
                if(++cnt == 11){
                    cout << "\n ";
                    cnt = 1;
                }
                cout << " (" << e.x << ',' << e.y << ")";
            }
        }else{
            cout << " No Solution Possible";
        }
        cout << '\n';
    }
}
