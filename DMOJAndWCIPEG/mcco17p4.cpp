#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 200010;
int n, m, col[MAXN], in[2][MAXN];
vi adj[MAXN];
deque<ii> dq;

int tsort(int c){
    fori(i, 0, n) {
        if (in[c][i]) continue;
        if(col[i] == c) dq.push_front(ii(i, c));
        else dq.push_back(ii(i, 1-c));
    }

    int cnt = 0, curr = c;
    while(dq.size()){
        ii u = dq.front();
        //cout << u.f << ", " << u.s << endl;
        if(u.s != curr){
            cnt++;
            curr = u.s;
        }
        dq.pop_front();
        for(int v : adj[u.f]){
            if(--in[c][v] == 0){
                if(col[v] == u.s) dq.push_front(ii(v, col[v]));
                else dq.push_back(ii(v, col[v]));
            }
        }
    }
    //cout << endl;
    return cnt;
}

int main(){
    scanf("%d%d", &n, &m);
    fori(i, 0, n) scanf("%d", col+i);
    fori(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        in[0][v]++;
        in[1][v]++;
    }

    int ans = min(tsort(0), tsort(1));
    cout << ans << endl;

    return 0;
}
