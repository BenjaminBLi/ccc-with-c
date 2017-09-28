#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int N, M, K;
vi adj[2010];
bool vis[2010][2010];

int main(){
    scanf("%d %d", &N, &M);
    scanf("%d", &K);

    for(int i = 0; i < K; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        vis[u][v] = true;
    }
    fori(i, 1, N+1) fori(j, i+1, N+1){
            int cnt = 0;
            for(int k : adj[i]) if(vis[j][k]) cnt++;
            if(cnt > 1){
                cout << "NO\n";
                return 0;
            }
        }
    cout << "YES\n";
    return 0;
}