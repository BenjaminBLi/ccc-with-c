#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <cstring>
#include <sstream>
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

const int MAXN = 3e5 + 10;
int en, n, q, l[MAXN], r[MAXN], k[MAXN];
unordered_map<ll, int> pos;
ll rev[MAXN<<1];
struct node{
    ll l, r;
    ll cnt, interval, lazy;
    bool flag;
    node *left, *right;
    node(){cnt = flag = l = r = 0;}

    inline void apply(ll val) {
        cnt = val * interval;
        lazy = val;
        flag = true;
    }

    inline void prop(){
        if(!flag) return;
        left->apply(lazy);
        right->apply(lazy);
        flag = false;
        lazy = -1;
    }

    inline void calc(){
        cnt = left->cnt + right->cnt;
    }

    void build(int cl, int cr){
        l = cl, r = cr;
        lazy = flag = false;
        left = new node(), right = new node();

        if(l == r){
            cnt = interval = rev[l] - rev[l-1];
            return;
        }

        left->build(cl, mid(cl, cr)), right->build(mid(cl, cr)+1, cr);
        calc();
        interval = left->interval + right->interval;
    }

    void upd(ll cl, ll cr, int val){
        if(cl <= l && r <= cr) {
            apply(val);
            return;
        }if(cl > r || cr < l) return;
        prop();
        left->upd(cl, cr, val), right->upd(cl, cr, val);
        calc();
    }
}*root;

int main(){
    scanf("%d%d",  &n, &q);
    fori(i, 1, q+1){
        scanf("%d%d%d", l+i, r+i, k+i);
        rev[i] = l[i]-1, rev[i+q] = r[i];
    }

    int sz = (q<<1)+1;
    rev[sz] = n;

    sort(rev+1, rev+sz+1);
    root = new node();
    root->build(1, sz);

    fori(i, 1, q+1){
        int cl = lower_bound(rev+1, rev+sz+1, l[i])-rev;
        int cr = upper_bound(rev+1, rev+sz+1, r[i])-rev-1;
        root->upd(cl, cr, k[i]-1);

        cout << root->cnt << "\n";
    }

    return 0;
}
