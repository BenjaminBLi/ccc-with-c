#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class dset{
    private: vi p, rnk, sz;
    public:
    dset(int N){
        rnk.assign(N, 0); p.assign(N, 0); sz.assign(N, 1);
        for(int i = 0;i < N; i++) p[i] = i;
    }
    int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool sameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!sameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rnk[x] > rnk[y]){
                p[y] = x;
                sz[y] += sz[x];
            }else{
                p[x] = y;
                sz[x] += sz[y];
                if(rnk[x] == rnk[y]) rnk[y]++;
            }
        }
    }
    int getSize(int i){return sz[findSet(i)];}
};

int N, M, awake[27];
char t;
int a, b;
vector<vi> adj;
bool in[26], sleep[26];
string line;
int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &N) != EOF){
        scanf("%d", &M);
        dset s(26);http:
        adj.assign(26, vi());
        memset(in, false, sizeof(in)); memset(sleep, false, sizeof(sleep));
        queue<int> q;
        for(int i = 0;i < 3; i++){
            scanf(" %c", &t);
            q.push((int) t - 'A');
            in[t-'A'] = true;
        }
        getline(cin, line);
        for(int i = 0; i < M; i++){
            getline(cin, line);
            //cout << line << endl;
            a = line[0] - 'A'; b = line[1] - 'A';
            in[a] = in[b] = true;
            adj[a].push_back(b); adj[b].push_back(a);
        }
        int asleep = N, years = 0;
        memset(awake, 0, sizeof(awake));
        while(!q.empty()){
            while(!q.empty()){
                int curr = q.front(); q.pop();
                if(sleep[curr]) continue;
                sleep[curr] = true;
                asleep--;
                //cout << curr << endl;
                for(int node : adj[curr]){
                    if(sleep[node]||s.sameSet(node, curr))continue;
                    //cout << node << endl;
                    awake[node]++;
                }
                //cout << curr << endl;
            }
            if(asleep == 0) break;
            years++;
            for(int i = 0; i < 26; i++){
                if(in[i] && awake[i] >= 3 && !sleep[i]) q.push(i);
            }
            //cout << endl;
        }
        if(asleep) printf("THIS BRAIN NEVER WAKES UP\n");
        else printf("WAKE UP IN, %d, YEARS\n", years);
    }
    return 0;
}
