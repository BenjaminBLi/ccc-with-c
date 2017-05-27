#include "bits/stdc++.h"
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
char _inp[4097];
char *_pinp = _inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

int visited[100010], N, M, T, S;
vi adj[100010];
bool valid, shares, seen[100010], cycle4, inCycle[100010];
vector<int> stk;
set<ii> edges;


void addE(int u, int v){
    //printf("<%d,%d>\n", u, v);
    ii id = {u, v};
    if(edges.count(id)) shares = true;
    edges.insert(id);
    id = {v, u};
    if(edges.count(id)) shares = true;
    edges.insert(id);
}

void dfs1(int u, int pre){
    if(shares) return;
    visited[u] = 1;
    stk.pb(u);
    for(int v : adj[u]){
        if(v == pre) continue;
        if(!visited[v]){
            dfs1(v, u);
        }else if(visited[v] == 1){
            addE(u, v);
            int last = stk.back();
            for(int i = (int)stk.size()-2; i >= 0; i--){
                addE(last, stk[i]);
                last = stk[i];
                if(stk[i] == v) break;
            }
        }
    }
    stk.pop_back();
    visited[u] = 2;
}

void dfs3(int u, int pre){
    if(shares || valid) return;
    visited[u] = 1;
    stk.pb(u);
    for(int v : adj[u]){
        if(v == pre) continue;
        if(!visited[v]) dfs3(v, u);
        else if(visited[v] == 1){
            addE(u, v);
            int last = stk.back();
            int cnt = 1;
            for(int i = (int)stk.size()-2; i >= 0; i--){
                addE(last, stk[i]);
                last = stk[i];
                cnt++;
                if(stk[i]==v) break;
            }
            valid |= (cnt >= 4);
        }
    }
    stk.pop_back();
    visited[u] = 2;
}

void dfs4(int u, int pre){
    visited[u] = 1;
    stk.pb(u);
    for(int v : adj[u]){
        if(v == pre) continue;
        if(!visited[v]) {
            dfs4(v, u);
        }
        else if(visited[v] == 1){
            int cnt = 0, nV = 1, vCnt = 0;
            memset(seen, false, sizeof(seen));
            memset(inCycle, false, sizeof(inCycle));
            queue<int> q;
            addE(u, v);
            int last = stk.back();
            if(adj[stk.back()].size() > 2) q.push(last), cnt++;
            for(int i = (int)stk.size()-2; i >= 0; i--){
                addE(last, stk[i]);
                last = stk[i];
                nV++;
                if(adj[stk[i]].size() > 2) {
                    q.push(stk[i]);
                    cnt++;
                }
                inCycle[stk[i]] = true;
                if(stk[i]==v) break;
            }
            while (q.size()) {
                int curr = q.front();
                q.pop();
                for (int w : adj[curr]) if (!seen[w] && !inCycle[w])  seen[w] = true, vCnt++;
            }
            valid |= (cnt >= 2) && (vCnt >= 2);
            cycle4 |= nV >= 4;
        }
    }
    stk.pop_back();
    visited[u] = 2;
}

int main(){
    //freopen("C:\\Users\\strik\\Downloads\\legends_tests\\final_legends.1.in", "r", stdin);
    scan(S); scan(T);
    if(S == 1){
        for(;T--;){
            stk.clear();
            for(int i = 0; i <= N; i++) adj[i].clear();
            memset(visited, 0, sizeof(visited));
            shares = false;
            edges.clear();

            scan(N); scan(M);
            for(int i = 0; i < M; i++){
                int u, v; scan(u); scan(v);
                adj[u].pb(v); adj[v].pb(u);
            }

            for(int i = 1; i <= N; i++) if(!visited[i]) dfs1(i, -1);

            if(shares) printf("YES\n");
            else printf("NO\n");
        }
    }else if (S == 2){
        for(;T--;){
            scan(N); scan(M);
            for(int i = 0; i <= N; i++) adj[i].clear();
            for(int i = 0; i < M; i++){
                int u, v; scan(u); scan(v);
                adj[u].pb(v); adj[v].pb(u);
            }
            if(M >= N) printf("YES\n");
            else printf("NO\n");
        }
    }else if (S == 3){
        for(;T--;){
            scan(N); scan(M);
            for(int i = 0;i <= N; i++) adj[i].clear();
            shares = false;
            valid = false;
            memset(visited, false, sizeof(visited));
            edges.clear();
            for(int i = 0;i < M; i++){
                int u, v; scan(u); scan(v);
                adj[u].pb(v); adj[v].pb(u);
            }
            for(int i = 0; i <= N; i++)if(!visited[i]) dfs3(i, -1);
            if(valid || shares) printf("YES\n");
            else printf("NO\n");
        }
    }else if (S == 4){
        for(;T--;){
            scan(N); scan(M);
            for(int i = 0; i <= N; i++) adj[i].clear();
            for(int i = 0; i < M; i++){
                int u, v; scan(u); scan(v);
                adj[u].pb(v), adj[v].pb(u);
            }
            bool valid = false;
            for(int i = 0; i <= N; i++){
                if((int) adj[i].size() >= 3) valid = true;
            }
            if(valid) printf("YES\n");
            else printf("NO\n");
        }
    }else if (S == 5){
        for(;T--;) {
            scan(N); scan(M);
            for (int i = 0; i <= N; i++) adj[i].clear();
            valid = false;
            cycle4 = false;
            shares = false;
            edges.clear();
            memset(visited, false, sizeof(visited));
            for (int i = 0; i < M; i++) {
                int u, v;
                scan(u);
                scan(v);
                adj[u].pb(v);
                adj[v].pb(u);
            }
            for (int i = 1; i <= N; i++)if (!visited[i]) dfs4(i, -1);
            if(N == 4 && M >= 5){
                if(shares) printf("NO\n");
                else if(valid) printf("YES\n");
                else printf("NO\n");
            }else if(N == 5 && M == 6){
                //cout << "YES" << endl;
                int vCnt = 0, fCnt=0, oCnt=0;
                set<int> tmp;
                queue<int> cont;
                for(int i = 1; i <= N; i++){
                    if((int)adj[i].size() == 4) fCnt++;
                    if((int) adj[i].size() == 1) oCnt++;
                    if((int)adj[i].size() == 3) {
                        vCnt++;
                        cont.push(i);
                        for(int v : adj[i]) tmp.insert(v);
                    }
                }
                bool ok = true;
                while(cont.size()){
                    ok &= tmp.count(cont.front()); cont.pop();
                }
                if((vCnt == 3 && shares && oCnt == 1 && tmp.size() > 2)||(vCnt == 2 && tmp.size() > 2 && (cycle4) && shares && ok)||(oCnt == 1 && fCnt == 1 && vCnt == 1)||(oCnt==1 && shares&&vCnt==2&&fCnt==0)) printf("YES\n");
                else printf("NO\n");
            }else {
                if (valid) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
