int p[100010], rnk[100010], sz[100010], nsets, N;

int fs(int i){return (p[i] == i) ? i : (p[i] = fs(p[i]));}
bool ss(int i, int j){return fs(i) == fs(j);};
void us(int i, int j){
    if(!ss(i, j)){
        int x = fs(i), y = fs(j);
        if(rnk[x] > rnk[y]){
            sz[fs(x)] += sz[fs(y)];
            p[y] = x;
        }else{
            sz[fs(y)] += sz[fs(x)];
            p[x] = y;
            if(rnk[x] == rnk[y]) rnk[y]++;
        }
        nsets++;
    }
}
