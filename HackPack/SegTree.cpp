#include <bits/stdc++.h>
using namespace std;
int tree[400010], arr[400010], lazy[400010], l[400010], r[400010], N, M;
char ch;


void prop(int idx){
    if(lazy[idx]){
        tree[idx] += lazy[idx];
        if(l[idx] != r[idx]){
            lazy[idx<<1] += lazy[idx];
            lazy[(idx<<1)+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}


void update(int vIdx, int idx, int val){
    if(l[idx] == r[idx]){
        tree[vIdx] = arr[idx] = val;
    }else{
        int mid = (st+en)>>1;
        if(l[vIdx] <= idx && idx <= mid){
            update(vIdx<<1, st, mid, idx, val);
        }else{
            update((vIdx<<1)+1, mid+1, en, idx, val);
        }
        tree[vIdx] = min(tree[vIdx<<1], tree[(vIdx<<1)+1]);
    }
}

void build(){
    for(int i = 1; i < N; i++) update(i)
}

void rUpdate(int vIdx, int st, int en, int l, int r, int val){
    if(lazy[vIdx] != 0){
        tree[vIdx] += (en-st+1)*lazy[vIdx];
        if(st != en){
            lazy[vIdx<<1] += lazy[vIdx];
            lazy[(vIdx<<1)+1] += lazy[vIdx];
        }
        lazy[vIdx] = 0;
    }
    if(st > en || st > r || en < l) return;
    if(st >= l && en <= r){
        tree[vIdx] += (en-st+1)*val;
        if(st != en){
            lazy[vIdx<<1] += val;
            lazy[(vIdx<<1)+1] += val;
        }
        return;
    }
    int mid = (st+en)<<1;
    rUpdate(vIdx<<1, st, mid, l, r, val);
    rUpdate((vIdx<<1)+1, mid+1, en, l, r, val);
    tree[vIdx] = min(tree[vIdx<<1], tree[(vIdx<<1)+1]);
}

int minQuery(int vIdx, int st, int en, int l, int r){
    if(st > en || st > r || en < l) return (int)1e9;
    if(st >= l && en <= r){
        return tree[vIdx];
    }
    int mid = (st+en)>>1;
    int p1 = minQuery(vIdx<<1, st, mid, l, r);
    int p2 = minQuery((vIdx<<1)+1, mid+1, en, l, r);
    return min(p1, p2);
}


int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", arr+i);
    build();
    int l, r;
    for(int i = 0; i < M; i++){
        scanf(" %c %d %d", &ch, &l, &r);
        if(ch == 'C') update(1, 1, N, l, r);
        if(ch == 'M') printf("%d\n", minQuery(1, 1, N, l, r));
        if(ch == 'G') printf("%d\n", gcdQ(1, 1, N, l, r));
        if(ch == 'Q') {
            printf("%d\n", freqQ(1, 1, N, l, r));
        }
    }
    return 0;
}
