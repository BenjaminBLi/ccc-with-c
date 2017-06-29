#include <bits/stdc++.h>
using namespace std;
int tree[400010][3], arr[400010], lazy[400010], N, M;
char ch;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void build(int cIdx, int l, int r){
    if(l == r){
        tree[cIdx][0] = tree[cIdx][1] = arr[l];
        tree[cIdx][2] = 1;
    }else{
        int mid = (l+r)>>1;
        build(cIdx<<1, l, mid);
        build((cIdx<<1)+1, mid+1, r);
        tree[cIdx][0] = min(tree[cIdx<<1][0], tree[(cIdx<<1)+1][0]);
        tree[cIdx][1] = gcd(tree[cIdx<<1][1], tree[(cIdx<<1)+1][1]);
        if(tree[cIdx][1] == tree[cIdx<<1][1]) tree[cIdx][2] += tree[cIdx<<1][2];
        if(tree[cIdx][1] == tree[(cIdx<<1)+1][1]) tree[cIdx][2] += tree[(cIdx<<1)+1][2];
    }
}

void update(int vIdx, int st, int en, int idx, int val){
    if(st == en){
        tree[vIdx][0] = tree[vIdx][1] = arr[idx] = val;
        tree[vIdx][2] = 1;
    }else{
        int mid = (st+en)>>1;
        if(st <= idx && idx <= mid){
            update(vIdx<<1, st, mid, idx, val);
        }else{
            update((vIdx<<1)+1, mid+1, en, idx, val);
        }
        tree[vIdx][0] = min(tree[vIdx<<1][0], tree[(vIdx<<1)+1][0]);
        tree[vIdx][1] = gcd(tree[vIdx<<1][1], tree[(vIdx<<1)+1][1]);
        tree[vIdx][2] = 0;
        if(tree[vIdx][1] == tree[vIdx<<1][1]) tree[vIdx][2] += tree[(vIdx<<1)][2];
        if(tree[vIdx][1] == tree[(vIdx<<1)+1][1]) tree[vIdx][2] += tree[(vIdx<<1)+1][2];
    }
}

void rUpdate(int vIdx, int st, int en, int l, int r, int val){
    if(lazy[vIdx] != 0){
        tree[vIdx][0] += (en-st+1)*lazy[vIdx];
        if(st != en){
            lazy[vIdx<<1] += lazy[vIdx];
            lazy[(vIdx<<1)+1] += lazy[vIdx];
        }
        lazy[vIdx] = 0;
    }
    if(st > en || st > r || en < l) return;
    if(st >= l && en <= r){
        tree[vIdx][0] = tree[vIdx][1] = tree[vIdx][2] += (en-st+1)*val;
        if(st != en){
            lazy[vIdx<<1] += val;
            lazy[(vIdx<<1)+1] += val;
        }
        return;
    }
    int mid = (st+en)<<1;
    rUpdate(vIdx<<1, st, mid, l, r, val);
    rUpdate((vIdx<<1)+1, mid+1, en, l, r, val);
    tree[vIdx][0] = min(tree[vIdx<<1][0], tree[(vIdx<<1)+1][0]);
}

int minQuery(int vIdx, int st, int en, int l, int r){
    if(st > en || st > r || en < l) return (int)1e9;
    if(st >= l && en <= r){
        return tree[vIdx][0];
    }
    int mid = (st+en)>>1;
    int p1 = minQuery(vIdx<<1, st, mid, l, r);
    int p2 = minQuery((vIdx<<1)+1, mid+1, en, l, r);
    return min(p1, p2);
}

int gcdQ(int vIdx, int st, int en, int l, int r){
    if(st > en || st > r || en < l) return 0;
    if(st >= l && en <= r){
        return tree[vIdx][1];
    }
    int mid = (st+en)>>1;
    int p1 = gcdQ(vIdx<<1, st, mid, l, r);
    int p2 = gcdQ((vIdx<<1)+1, mid+1, en, l, r);
    return gcd(p1, p2);
}

int freqQ(int vIdx, int st, int en, int l, int r){
    if(st > en || st > r || en < l) return 0;
    if(st >= l && en <= r){
        return tree[vIdx][2];
    }
    int mid = (st+en)>>1;
    int g1 = gcdQ(vIdx<<1, st, mid, l, r);
    int g2 = gcdQ((vIdx<<1)+1, mid+1, en, l, r);
    int p1 = freqQ(vIdx<<1, st, mid, l, r);
    int p2 = freqQ((vIdx<<1)+1, mid+1, en, l, r);
    int ret = 0;
    int gt = gcd(g1, g2);
    if(g1 == gt) ret += p1;
    if(g2 == gt) ret += p2;
    return ret;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf("%d", arr+i);
    build(1, 1, N);
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
