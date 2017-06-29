#include "bits/stdc++.h"
using namespace std;
int tree[8010], arr[8010], lazy[8010], id[2010], N, M;
char ch;
long long hshs[2010][5010];

int find(int a, int b, int lo, int hi){
    int ans = -1;
    int mid;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if (hshs[a][mid] == hshs[b][mid]) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

void build(int cIdx, int l, int r){
    if(l == r) {
        tree[cIdx] = M-1;
        return;
    }
    int mid = (l+r)>>1;

    build(cIdx<<1, l, mid);
    build((cIdx<<1)+1, mid+1, r);

    tree[cIdx] = find(id[l], id[r], 0, min(tree[cIdx<<1], tree[(cIdx<<1)+1]));
}

void update(int vIdx, int st, int en, int idx) {
    if (st == en) {
        return;
    }
    int mid = (st + en) >> 1;
    if (idx <= mid) {
        update(vIdx << 1, st, mid, idx);
    } else {
        update((vIdx << 1) + 1, mid + 1, en, idx);
    }
    int mn = min(tree[vIdx << 1], tree[(vIdx << 1) + 1]);
    tree[vIdx] = find(id[st], id[en], 0, mn);
}

int query(int vIdx, int st, int en, int l, int r){
    if(st > r || en < l) return -2;

    if(st >= l && en <= r){
        return tree[vIdx];
    }
    int mid = (st+en)>>1;
    int p1 = query(vIdx<<1, st, mid, l, r);
    int p2 = query((vIdx<<1)+1, mid+1, en, l, r);
    if(p1 == -2) return p2;
    else if(p2 == -2) return p1;

    return find(id[max(l, st)], id[min(r, en)], 0, min(p1, p2));
}

long long seed = 31;

void genHsh(string& a, int idx){
    long long curr = 1;
    for(int i = 0; i < M; i++){
        curr = curr*seed + (long long) (a[i] - '0');
        hshs[idx][i] = curr;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;
        genHsh(tmp, i);
        id[i] = i;
    }
    build(1, 1, N);
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        cout << ((query(1, 1, N, a, b) + 1) * (b - a + 1)) << "\n";
        swap(id[a], id[b]);
        update(1, 1, N, b);
        update(1, 1, N, a);
    }

    return 0;
}
