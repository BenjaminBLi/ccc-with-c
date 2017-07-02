#include "bits/stdc++.h"
#define ll long long
using namespace std;

int N;
ll tree[400010][3], arr[100010];

//0 = left, 1 = mid, 2 = right

void build(int cIdx, int l, int r){
    if(l == r) {
        tree[cIdx][0] = tree[cIdx][1] = tree[cIdx][2] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    int lIdx = cIdx<<1;
    int rIdx = (cIdx<<1)+1;

    build(lIdx, l, mid);
    build(rIdx, mid+1, r);

    if(tree[lIdx][2] >= 0) {
        tree[cIdx][1] += tree[lIdx][2];
        tree[cIdx][2] += tree[lIdx][2];
    }if(tree[rIdx][0] >= 0){
        tree[cIdx][0] += tree[rIdx][0];
        tree[cIdx][1] += tree[rIdx][0];
    }
}

void update(int vIdx, int st, int en, int idx, int val) {
    if (st == en) {
        tree[vIdx][0] = tree[vIdx][1] = tree[vIdx][2] = val;
        return;
    }

    int mid = (st + en) >> 1;
    if (idx <= mid)
        update(vIdx << 1, st, mid, idx, val);
    else
        update((vIdx << 1) + 1, mid + 1, en, idx, val);

    tree[vIdx][1] = tree[vIdx<<1][2] + tree[(vIdx<<1)+1][0];
}

ll query(int vIdx, int st, int en, int l, int r){
    if(st > r || en < l) return 0;

    if(st >= l && en <= r){
        return tree[vIdx][1];
    }
    int mid = (st+en)>>1;
    ll p1 = query(vIdx<<1, st, mid, l, r);
    ll p2 = query((vIdx<<1)+1, mid+1, en, l, r);

    return p1+p2;

}

int main(){
    int Q;
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++) scanf("%lld", arr+i);
    return 0;
}

