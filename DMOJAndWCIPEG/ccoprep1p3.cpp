#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define tsz() order_of_key(1000000000)
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> bbst;

const int MAXN = 100010;
int n, m, rnk[MAXN], val[MAXN], rev[MAXN];
bbst *group[MAXN];

//dsu stuff
void init(){fori(i, 0, MAXN) rnk[i] = -1;}
int fs(int u){return rnk[u] < 0 ? u : rnk[u] = fs(rnk[u]);}
bool us(int u, int v){
    if((u = fs(u)) != (v = fs(v))){
        if(rnk[u] > rnk[v]) swap(u, v);
        rnk[u] += rnk[v];
        rnk[v] = u;
        return true;
    }
    return false;
}

// BiG iNtO sMaLl
void merge(int a, int b){
    a = fs(a), b = fs(b);
    if(us(a, b)){
        int big = a, small = b;
        int sza = group[a]->tsz(), szb = group[b]->tsz();

        int cnt = szb;
        if(sza < szb) swap(big, small), cnt = sza;

        fori(i, 0, cnt){
            int c = *group[small]->find_by_order(i);
            group[big]->insert(c);
        }
    }
}

inline void prnt(int u){
    u = fs(u);
    int sz = group[u]->tsz();
    fori(i, 0, sz){
        printf("%d, ", rev[*group[u]->find_by_order(i)]);
    }
    cout<<endl;
}

int main(){
    scanf("%d%d", &n, &m);
    fori(i, 1, n+1) {
        scanf("%d", val+i);
        rev[val[i]] = i;
        group[i] = new bbst();
        group[i]->insert(val[i]);
    }

    init();
    for(int i = 0, u, v; i < m; i++){
        scanf("%d%d", &u, &v);
        merge(u, v);
    }


    int q;
    scanf("%d", &q);
    for(;q--;) {
        char ch;
        int a, b;
        scanf(" %c%d%d", &ch, &a, &b);
        if (ch == 'B') {
            merge(a, b);
            //prnt(a);prnt(b);cout << endl;
        } else {
            if(b > group[fs(a)]->tsz()) printf("-1\n");
            else printf("%d\n", rev[*group[fs(a)]->find_by_order(b-1)]);
        }
    }

    return 0;
}

