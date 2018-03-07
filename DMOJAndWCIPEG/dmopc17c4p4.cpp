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

const int MAXN = 1000010;
int n, ans[MAXN], a[MAXN];
unordered_set<int> rem, other;
vi q;

int main(){
    scanf("%d", &n);

    if(n == 1){
        printf("-jj1\n");
        return 0;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
        if(rem.count(a[i]) == 0) q.pb(a[i]);
        rem.insert(a[i]);
    }

    fori(i, 1, n+1){
        if(rem.count(i)) continue;
        other.insert(i);
    }

    if(rem.size() == 1) {
        printf("-1\n");
        return 0;
    }

    int pos = 0, sz = q.size();
    fori(i, 0, n){
        if(rem.count(a[i]) == 0) continue;
        rem.erase(a[i]);
        ans[i] = q[(++pos)%sz];
        pos %= sz;
    }

    fori(i, 0, n){
        if(ans[i]) continue;
        ans[i] = *other.begin();
        other.erase(other.begin());
    }

    fori(i, 0, n) printf("%d ", ans[i]); cout << endl;
    return 0;
}