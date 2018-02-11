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

const int MAXN = 100010, rt = 320;
struct qry{
    int l, r, id;
    qry(){l = r = id = 0;}
    bool operator < (const qry &o){
        if(l/rt != o.l/rt) return l/rt < o.l/rt;
        if(r != o.r) return r < o.r;
        return id < o.id;
    }
}qs[MAXN];

int n, a[MAXN], q, ans[MAXN], freq[MAXN], cl, cr, cnt;

inline bool valid(int i){return freq[a[i]]>0 && !(freq[a[i]]&1);}

inline void add(int i){
    bool ok = valid(i);
    freq[a[i]]++;
    if(!ok && valid(i)) cnt++;
    else if(ok && !valid(i)) cnt--;
}

inline void rem(int i){
    bool ok = valid(i);
    freq[a[i]]--;
    if(ok && !valid(i)) cnt--;
    else if(!ok && valid(i)) cnt++;
}

int main(){
    scanf("%d", &n);
    fori(i, 1, n+1) scanf("%d", a+i);
    scanf("%d", &q);
    fori(i, 0, q){
        scanf("%d%d", &qs[i].l, &qs[i].r);
        qs[i].id = i;
    }
    sort(qs, qs+q);

    cl = 1, cr = 1, cnt = 0;
    fori(i, 0, q){
        //printf("[%d, %d], previous: %d\n", qs[i].l, qs[i].r, cnt);
        while(cl < qs[i].l) rem(cl++);
        while(cl > qs[i].l) add(--cl);
        while(cr <= qs[i].r) add(cr++);
        while(cr > qs[i].r+1) rem(--cr);
        
        //printf("[%d, %d], ans: %d\n", qs[i].l, qs[i].r, cnt);
        //fori(i, 1, n+1) printf("%d, ", freq[i]); cout << endl;

        ans[qs[i].id] = cnt;
    }

    fori(i, 0, q)
        printf("%d\n", ans[i]);
    return 0;
}

