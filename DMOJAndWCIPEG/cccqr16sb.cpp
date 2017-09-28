#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int N, a, k, sz[100002], ans[100002], first[100002];
set<int> nodes;
vector<vi> adj;
vector<ii> loop;
set<ii> taken;
map<int, int> id[100001];
unordered_map<int, ii> seen;

int main(){
    scanf("%d", &N);
    adj.assign(N, vi()); memset(ans, 0, sizeof(ans));
    for(int i = 0; i < N; i++){
        scanf("%d", &sz[i]);
        for(int j =0 ; j < sz[i]; j++){
            scanf("%d", &a);
            a--;
            adj[i].push_back(a);
            id[i][a] = j;
        }
    }
    int curr, last, pos, sze;
    ii c;
    vi loop;
    for(int u = 0; u < N; u++){
        //printf("START: %d:\n", u+1);
        for(int v : adj[u]){
            c = ii(u, v);
            if(taken.count(c) == 0){
               // printf("NEXT: %d\n", v+1);
                int idx = 0;
                loop.clear();
                seen.clear();
                for(int i = u, j = v; !idx || (i != u || j != v); idx++){
                    //printf("%d %d\n", i+1, j+1);
                    c = ii(i, j);
                    loop.push_back(j);
                    taken.insert(c);
                    if(seen.count(i) == 0){
                        seen[i] = ii(idx, -1);
                        first[i] = idx;
                    }else{
                        ii tmp = seen[i];
                        ans[i] = max(ans[i], idx-tmp.first);
                        seen[i] = ii(idx, tmp.first);
                    }
                    int tmpIdx = (id[j][i]-1+sz[j])%sz[j];
                    i = j; j = adj[j][tmpIdx];
                }
                //for(int n : loop)printf("%d ", n+1);
                //cout << endl;
                for(auto it : seen){
                    if(it.second.second == -1) ans[it.first] = max(ans[it.first], (int) loop.size());
                    else ans[it.first] = max(ans[it.first], (int) loop.size()+first[it.first]-it.second.first);
                }
            }
        }
    }
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        scanf("%d", &a); a--;
        printf("%d\n", ans[a]);
    }
    //cout << "DONE" << endl;
    return 0;
}
