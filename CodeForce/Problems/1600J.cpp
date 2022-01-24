#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1e6 + 5;

int djs[MAXLEN]  = {0};                                                                          

int sz[MAXLEN] = {0};


int find(int u){return u  == djs[u] ? u : djs[u] = find(djs[u]);}

int dir[4][2] = {0, -1, 1, 0, 0, 1, -1, 0};


int main(){
	int n, m;
	scanf(" %d %d", &n, &m);
	int num;
	for(int i = 0; i < n * m; ++i) djs[i] = i, sz[i] = 1;
	
		
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf(" %d", &num);
			for(int d = 0; d < 4; ++d)if(!(num & (1 << d))){
					int nx = i + dir[d][0], ny = j + dir[d][1];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
					int pa = find(i * m + j), pb = find(nx * m + ny);
					if(pa != pb)djs[pa] = pb, sz[pb] += sz[pa];
					                                           
			}
			
						
		}	

	}
	vector<int> ans;
	for(int i = 0; i < n * m; ++i) if(find(i) == i)ans.push_back(sz[i]);
	sort(ans.begin(), ans.end());
	for(int i = ans.size() - 1; i >= 0; --i)printf("%d ", ans[i]);
	printf("\n");

}