#include "bits/stdc++.h"
#define pb push_back
using namespace std;
typedef vector<int> vi;
char _inp[4097];
char *_pinp = _inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

/*
5 6
2 4
5 3
2 5
4 3
4 1
3 1
 */

int visited[100010], N, M, T, S;
vi adj[100010];
bool valid, shares;
vector<int> stk;
set<string> edges;

void addE(int u, int v){
    string id = "";
    id += '0'+u, id += " ", id += '0'+v;
    if(edges.count(id)) shares = true;
    edges.insert(id);
    id = "";
    id += '0'+v, id += " ", id += '0'+u;
    if(edges.count(id)) shares = true;
    edges.insert(id);
}

void dfs1(int u, int pre){
    //FIX IT PLZ
    cout << u << endl;
    visited[u] = 1;
    stk.pb(u);
    for(int v : adj[u]){
        if(v == pre) continue;
        if(!visited[v]){
            dfs1(v, u);
        }else if(visited[v] == 1){
            addE(u, v);
            cout << "out: <" << u << ", " << v << ">" << endl;
            int last = stk.back();
            for(int i = (int)stk.size()-2; i >= 0; i--){
                addE(last, stk[i]);
                cout << "in: <" << last << ", " << stk[i] << ">" << endl;
                last = stk[i];
                if(stk[i] == v) break;
            }
        }
    }
    stk.pop_back();
    visited[u] = 2;
}

void dfs3(int u, int pre){
    //still broken...
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
            valid |= cnt >= 4;
        }
    }
    stk.pop_back();
    visited[u] = 2;
}

int main(){
    freopen("C:\\Users\\strik\\Downloads\\legends_tests\\final_legends.1.in", "r", stdin);
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
            for(int i = 0;i < M; i++){
                int u, v; scan(u); scan(v);
                adj[u].pb(v); adj[v].pb(u);
            }
            for(int i = 0; i <= N; i++)if(!visited[i]) dfs3(i, -1);
            if(valid) printf("YES\n");
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
        printf("-1");
    }

    return 0;
}
